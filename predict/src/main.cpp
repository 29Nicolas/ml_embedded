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
	if(!file_s.is_open()){
		cout << "Erreur: fichier non trouvé" << endl;
		return;
	}

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
        sigma[i] = (sigma[i]-means[i+N])/scales[i+N];
    }
}

void traitementDecisionTree(string file_path, double mu[], double sigma[]){
	string path_model = "../model/model_DecisionTreeClassifier_ml.csv";
	double means[2*N]; 
	double scales[2*N];
	ifstream f(path_model);
	lectureModelNormalisation(f, means, scales);

	normalisation(mu, sigma, means, scales);
	int a = decision_tree(mu, sigma);
}

void produitMatriciel(double A[][1024], double B[], double C[]){
	double c; 
	for(int i=0; i<10; i++){
		c = 0;
		for(int k=0; k<1024; k++){
			c += A[i][k] * B[k];
			// if(i==1)
			// 	cout << c << " " << A[i][k] << " " << B[k] << endl;
		}
		C[i] = c;
	}
}

void transformationMatriceB(double B[], double mu[], double sigma[]){
	for(int j=0; j<512; j++){
		B[j] = mu[j];
		B[j+N] = sigma[j];
	}
}

void lectureMatriceSvc(ifstream &f, double A[][1024]){
	if(f.is_open()){
		char virgule;
		for(int j=0; j<10; j++){
			for(int k=0; k<1023; k++){
				f >> A[j][k];
				f >> virgule;
			}
			f >> A[j][1023];
		}
	}
}

void traitementSvc(string file_path, double mu[], double sigma[]){
	string path_model = "../model/model_svm.csv";
	double means[2*N]; 
	double scales[2*N];
	ifstream f(path_model);
	lectureModelNormalisation(f, means, scales);
	normalisation(mu, sigma, means, scales);
	double B[1024];
	transformationMatriceB(B, mu, sigma);
	double A[10][1024];
	lectureMatriceSvc(f, A);
	
	double C[10];
	produitMatriciel(A, B, C);

	for(int j = 0; j< 10; j++){
		cout << C[j] << endl;
	}
}

int main(int argc, char** argv){

	string file_path = "../../archive/genres/";

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
	file_path = file_path + '/' + argv[1] + ".au";

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
			else{
				ofstream f1("../script/descripteur.csv");
				for(int i=0; i<512; i++){
					f1 << mu[i]; 
					f1 << ",";
				}
				for(int i=0; i<511; i++){
					f1 << sigma[i]; 
					f1 << ",";
				}
				f1 << sigma[511]; 
			}
		}
		return 0;
	}	
}