#include <iostream>
#include <fstream>
#include "../utils/extraction_descripteur.h"
#include "../utils/utils_function.h"
#include <complex>
#include <map>

using namespace std;

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
	string path_modelSVC = "model_svm.csv";

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

    //declaration des variables utiles
    double mu[N];
    double sigma[N];
    double means[2*N]; 
    double scales[2*N];
    
    //extraction des descripteurs
    extraction_descripteur(file_path, mu, sigma);

    // traitement model SVC
    ifstream f(path_modelSVC);
    lectureModelNormalisation(f, means, scales);
    normalisation(mu, sigma, means, scales);
    int a = linearSVC(f, mu, sigma);
}