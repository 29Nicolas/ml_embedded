#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include "../utils/extraction_descripteur.h"
#include <complex>
#include <map>

using namespace std;

void lectureModelNormalisation(ifstream &f, Eigen::VectorXd& means, Eigen::VectorXd& scales){
	if(f.is_open()){
		char virgule;
		for(int i = 0; i<(2*N)-1; i++){
			f >> scales(i);
			f >> virgule;
		}
		f >> scales(2*N-1);
		
		for(int i=0; i<2*N-1; i++){
			f >> means(i); 
			f >> virgule;
		}
		f >> means(2*N-1);
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

void lectureModel(ifstream &f, Eigen::MatrixXd& coef, Eigen::VectorXd& intercept){
	if(f.is_open()){
		char virgule;
		for(int j=0; j<10; j++){
			for(int k=0; k<1023; k++){
				f >> coef(j,k);
				f >> virgule;
			}
			f >> coef(j,1023);
		}
		for(int j=0;j<9; j++){
			f >> intercept(j);
			f >> virgule;
		}
		f >> intercept(9);
	}
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

	// déclaration des variables
	Eigen::VectorXd descripteur(2*N);
	Eigen::VectorXd means(2*N);
	Eigen::VectorXd scales(2*N);
	Eigen::MatrixXd coef(10, 2*N);
	Eigen::VectorXd intercept(10);
	Eigen::VectorXd result(10);
	map<int, string> label;

	// lecture des informations dans le fichier csv
	ifstream f(path_modelSVC);
    lectureModelNormalisation(f, means, scales);
	lectureModel(f, coef, intercept);
	lectureLabel(f, label);

    //declaration des variables utiles
    double mu[N];
    double sigma[N];
    
    //extraction des descripteurs
    extraction_descripteur(file_path, mu, sigma);

	// normalisation + mise en forme pour l'application du modele
	for(int k=0; k< N; k++){
		descripteur(k) = (mu[k]-means(k))/scales(k);
		descripteur(k+N) = (sigma[k]-means(k+N))/scales(k+N);
	}

	// prediction
	result = coef*descripteur - intercept;

	// affichage du resultat de la prediction
	Eigen::Index indice;
	result.maxCoeff(&indice);
	cout << label[indice] << endl;
}