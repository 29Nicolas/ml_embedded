#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "fft_utils.h"
#include <complex>
#include <filesystem>
#include <dirent.h>
#include <stdio.h>
// #include <omp.h>
#include <vector>
using namespace std;

int read32Bits(ifstream &file_s){
	int result = 0;
	unsigned char byte;
	for(int i=0; i<4; i++){
		byte = file_s.get();
		result = result << 8|(int)byte;
	}
	return result;
}

int readNBits(ifstream &file_s, int n){
	int result = 0;
	unsigned char byte;
	for(int i=0; i<n; i++){
		byte = file_s.get();
		result = result << 8|(int)byte;
	}
	return result;
}

int readSample(ifstream &file_s){
	short sample = 0;
	unsigned char byte;
	for (int i=0; i<2; i++){
		byte = file_s.get();
		sample = sample << 8|(int)byte;
	}
	return (int)sample;
}

void extraction_descripteur(string file_name, ofstream &file_o){
	ifstream file_s;
	file_s.open(file_name);
	

	int p = file_s.tellg();
	int nb_magique = read32Bits(file_s);

	// cout << nb_magique << endl;
	int dataoffset = read32Bits(file_s);
	
	int data_size = read32Bits(file_s);
	// cout << "datasize " << data_size << endl;

	int encoding = read32Bits(file_s);
	// cout << "encodage " << encoding << endl;
	int frequency = read32Bits(file_s);
	// cout << "frequency " << frequency << endl;
	int nb_canaux = read32Bits(file_s);
	// cout << "nb_canaux " << nb_canaux << endl;

	file_s.seekg(p+dataoffset);
	// cout << p+dataoffset+data_size << endl;
	int Data[L];
	int real_size = 0;
	while (file_s.tellg() != -1 and real_size <= L){
		Data[real_size] = readSample(file_s);
		real_size++;
	}

	// verification lecture fichier avec python
	// for(int i=0; i < 9; i++)
	// 	file_o << Data[i] << ",";
	// file_o << Data[9];

	// remplissage des données par 0 quand audio trop petit
	if(real_size < L){
		for(int i=real_size; i<L; i++)
			Data[i] = 0;
	}

	double mu[N];
	double sigma[N];
	double s;

	for(int i=0; i<K; i++){
		vector<Complex> echantillon;
		for(int j =0; j < N; j++){
			echantillon.push_back(Data[i*N+j]);
		}

		ite_dit_fft(echantillon);
		for(int j=0; j<N; j++){
			double module = norm(echantillon[j]);
			if(i==0){
				mu[j] = module;
				sigma[j] = 0;
				s = module;
			}
			else if (i==1){				
				mu[j] = ((i-1.)/i) * mu[j] + (1.0/i)*module;
				sigma[j] = (1/2)*((s-mu[j])*(s-mu[j]) + (module-mu[j])*(module-mu[j]));
				s += module;				
			}
			else{
				s += module;
				mu[j] = ((i-1.)/i) * mu[j] + (1.0/i)*module;
				sigma[j] = (sigma[j] + (i*module-s)*(i*module-s)/(i*(i-1.)))/512.0;
			}
		}
	}

	// #pragma critical
	// {
		// cout << file_name << endl;
	for(int k=0; k<N; k++)
		file_o << mu[k] << ",";
	
	for(int k=0; k<N; k++)
		file_o << sigma[k] << ",";

	char caractere = file_name[22];
	int i = 22;
	while(caractere != '/'){
		file_o << caractere;
		// cout << caractere;
		i++;
		caractere = file_name[i];
	}
	file_o << ","; 
	i++;
	caractere = file_name[i];
	while (caractere != '.'){
		file_o << caractere;
		// cout << caractere;
		i++;
		caractere = file_name[i];
	}

	file_o << caractere;
	// cout << caractere;
	i++;
	caractere = file_name[i];

	while (caractere != '.'){
		file_o << caractere;
		// cout << caractere;
		i++;
		caractere = file_name[i];
	}
	file_o << endl;
// }

	// cout << endl;
}

vector<string> extraction_nom_fichier(string path, int &nb_fichier){
	nb_fichier = 0;
    struct dirent *dir;
    struct dirent *dire;
    const char* chemin = path.c_str();
    DIR *d = opendir(chemin); 
    vector<string> nom_fichier;
    if (d){
        while ((dir = readdir(d)) != NULL){
                string nom = dir->d_name;
                if(nom[0] !='.'){
                    nom = path + "/" + nom;
                    const char *c = nom.c_str();
                    DIR *e = opendir(c); 
                    while ((dire = readdir(e)) != NULL){
                        string nom_mus = dire->d_name;
                        if(nom_mus[nom_mus.length()-3] =='.' and nom_mus[nom_mus.length()-2] == 'a' and nom_mus[nom_mus.length()-1] == 'u'){
	                        nom_mus = nom + "/" + nom_mus;
	                        nom_fichier.push_back(nom_mus);
	                        nb_fichier++;
                    	}
                    }
                    closedir(e);
                }
        }
        closedir(d);
    }
    return nom_fichier;
}

int main(){
	string file_path = "../../archive/genres/";

	string file_o_name = "../../predict/model/output.csv";
	ofstream file_o;
	file_o.open(file_o_name);

	// double start = omp_get_wtime();
	
    int nb_fichier = 0;
	vector<string> nom_fichier = extraction_nom_fichier(file_path, nb_fichier);

	int count2 = 0;
	// #pragma omp parallel for
	for (int i =0; i<nb_fichier; i++)
	{
        extraction_descripteur(nom_fichier[i], file_o);

    //     #pragma omp critical
    //     {
    //     cout << "nommbre de thread " << omp_get_thread_num() << endl;
    //     cout << count2 << endl;
    //     count2++;
    // } 

    }
    // double end = omp_get_wtime();
    // cout << "temps execution : " << end-start << endl;
}
