#include <iostream>
#include <fstream>
#include "constants.h"
#include "fft_utils.h"
#include <complex>
#include "code.h"

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

void extraction_descripteur(string file_name, double mu[], double sigma[]){

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
}

void lectureModelNormalisation(ifstream &f, double means[], double scales[]){
	if(f.is_open()){
		char virgule;
		for(int i = 0; i<(2*N)-1; i++){
			f >> scales[i];
			f >> virgule;
		}
		f >> scales[2*N-1];
		
		for(int i=0; i<2*N-1; i++){
			f >> means[i]; 
			f >> virgule;
		}
		f >> means[2*N-1];
	}
}

void normalisation(double mu[], double sigma[], double means[], double scales[]){
    for(int i = 0; i<N; i++){
        mu[i] = (mu[i]-means[i])/scales[i];
        sigma[i+2*N] = (sigma[i+2*N]-means[i+2*N])/scales[i+2*N];
    }
}

void traitementDecisionTree(string file_path, double mu[], double sigma[]){
	// cout << argv[i] << endl;
	string path_model = "../model/model_DecisionTreeClassifier_ml.csv";
	double means[2*N]; 
	double scales[2*N];
	ifstream f(path_model);
	lectureModelNormalisation(f, means, scales);

	normalisation(mu, sigma, means, scales);

	int a = decision_tree(mu, sigma);
	cout << a << endl;
}

void traitementSvc(string file_path, double mu[], double sigma[]){
	string path_model = "../model/model_svm.csv";
	double means[2*N]; 
	double scales[2*N];
	ifstream f(path_model);
	lectureModelNormalisation(f, means, scales);
	normalisation(mu, sigma, means, scales);
	
	

	cout << "traitement svc" << endl;
}

int main(int argc, char** argv){

	string file_path = "../archive/genres/";

	if(argc == 1){
		cout << "choisir la musique a traité" << endl;
		return 0;
	}

	string mus = argv[1];
	int i = 0;
	char caract = mus[i];
	while(caract != '.'){
		i++;
		file_path += caract;
		caract = mus[i];
	}
	file_path = file_path + '/' + argv[1];
	// cout << file_path << endl;

	vector<char*> model;
	int nb_model = 2;
	model.push_back("decisionTree");
	model.push_back("svc");

	if(argc == 2){
		cout << "choisir le model d'IA à utiliser" << endl;
	}
	else{
		double mu[N];
		double sigma[N];
		extraction_descripteur(file_path, mu, sigma);

		for (int i = 2; i < argc; ++i){
			if(*argv[i] == *model[0]){
				traitementDecisionTree(file_path, mu, sigma);
			}
			else if(*argv[i] == *model[1]){
				traitementSvc(file_path, mu, sigma);
			}
		}
		return 0;
	}	
}