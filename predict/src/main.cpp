#include <iostream>
#include <fstream>
#include "constants.h"
#include "fft_utils.h"
#include <complex>
#include "codeDecisionTree.h"
#include "codeRandomForest.h"
#include <map>

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

void produitMatricielSoustraction(double A[][1024], double B[], double D[], double resultat[]){
	double c; 
	for(int i=0; i<10; i++){
		c = 0;
		for(int k=0; k<1024; k++){
			c += A[i][k] * B[k];
			// if(i==1)
			// 	cout << c << " " << A[i][k] << " " << B[k] << endl;
		}
		resultat[i] = c - D[i];
	}
}

void transformationMatriceB(double B[], double mu[], double sigma[]){
	for(int j=0; j<512; j++){
		B[j] = mu[j];
		B[j+N] = sigma[j];
	}
}

void lectureMatriceSvc(ifstream &f, double A[][1024], double intercept[]){
	if(f.is_open()){
		char virgule;
		for(int j=0; j<10; j++){
			for(int k=0; k<1023; k++){
				f >> A[j][k];
				f >> virgule;
			}
			f >> A[j][1023];
		}
		for(int j=0;j<9; j++){
			f >> intercept[j];
			f >> virgule;
		}
		f >> intercept[9];
	}
}

// int maxTableau(double tableau[10]){
// 	double max = tableau[0];
// 	int index_max = 0;
// 	for(int i=0;i<10;i++){
// 		if(max<tableau[i]){
// 			index_max = i;
// 			max = tableau[i];
// 		}
// 	}
// 	return index_max;
// }

void lectureLabel(ifstream &f, map<int, string> &label){
	if(f.is_open()){
		string str;
		getline(f, str);
		getline(f, str);
		// cout << str << endl;
		int j=0;
		string A = ""; 
		for(int i=0; i<str.size(); i++){
			if(str[i]!=','){
				A = A+str[i];
			}
			else{
				label[j] = A;
				j++;
				A = "";
			}
			label[j] = A;
		}
	}
}

int linearSVC(ifstream &f, double mu[], double sigma[]){
	double descripteur[1024];
	double coef[10][1024];
	double intercept[10];
	map<int, string> label;
	double resultat[10];

	//lecture des donnees du modele
	transformationMatriceB(descripteur, mu, sigma);
	lectureMatriceSvc(f, coef, intercept);
	lectureLabel(f, label);

	//prediction du genre de la musique
	produitMatricielSoustraction(coef, descripteur, intercept, resultat);
	int resultat_max = maxTableau(resultat);
	cout << label[resultat_max] << endl;
	return resultat_max;
}

int main(int argc, char** argv){

	//chemin vers les echantillons de musique et les modeles
	string file_path = "../../archive/genres/";
	string path_modelDecisionTree = "../model/model_DecisionTreeClassifier_ml.csv";
	string path_modelRandomForest = "../model/modelRandomForest.csv";
	string path_modelSVC = "../model/model_svm.csv";

	// different model d'ia (choix dans le 2eme argument de l'executable)
	vector<char*> model;
	int nb_model = 2;
	model.push_back("decisionTree");
	model.push_back("svc");
	model.push_back("randomForest");

	// premier argument: nom de la musique a traiter
	if(argc == 1){
		cout << "choisir la musique a traiter" << endl;
		return 0;
	}

	//recuperation du chemin de la musique
	string mus = argv[1];
	int i = 0;
	char caract = mus[i];
	while(caract != '.'){
		i++;
		file_path += caract;
		caract = mus[i];
	}
	file_path = file_path + '/' + argv[1] + ".au";

	//2e argument: nom du modele d'ia a utiliser (possible de choisir plusieurs modeles en meme temps)
	if(argc == 2){
		cout << "choisir le model d'IA à utiliser" << endl;
	}
	else{
		//traitement de chaque modele
		for (int i = 2; i < argc; ++i){
			//declaration des variables utiles
			double mu[N];
			double sigma[N];
			double means[2*N]; 
			double scales[2*N];
			
			//extraction des descripteurs (methode commune pour tous les modeles)
			extraction_descripteur(file_path, mu, sigma);

			if(*argv[i] == *model[0]){
				// Decision Tree
				ifstream f(path_modelDecisionTree);
				lectureModelNormalisation(f, means, scales);
				normalisation(mu, sigma, means, scales);
				int a = decision_tree(mu, sigma);
			}
			else if(*argv[i] == *model[1]){
				// SVM
				ifstream f(path_modelSVC);
				lectureModelNormalisation(f, means, scales);
				normalisation(mu, sigma, means, scales);
				int a = linearSVC(f, mu, sigma);
			}
			else if(*argv[i] == *model[2]){
				// Random Forest
				ifstream f(path_modelRandomForest);
				lectureModelNormalisation(f, means, scales);
				normalisation(mu, sigma, means, scales);
				int a = randomForest(mu, sigma);
			}
			else{
				//enregistrement des descripteurs dans un CSV pour être traité ailleurs
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