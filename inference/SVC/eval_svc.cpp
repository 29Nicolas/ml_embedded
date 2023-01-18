#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include "test_dataset.h"
#include <complex>
#include <map>

using namespace std;

void lectureModelNormalisation(ifstream &f, Eigen::VectorXd& means, Eigen::VectorXd& scales){
	if(f.is_open()){
		char virgule;
		for(int i = 0; i<(N_FEATURES)-1; i++){
			f >> scales(i);
			f >> virgule;
		}
		f >> scales(N_FEATURES-1);
		
		for(int i=0; i<N_FEATURES-1; i++){
			f >> means(i); 
			f >> virgule;
		}
		f >> means(N_FEATURES-1);
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
    //chemin le modele
	string path_modelSVC = "model_svm.csv";

	// déclaration des variables
	Eigen::VectorXd descripteur(N_FEATURES);
	Eigen::VectorXd means(N_FEATURES);
	Eigen::VectorXd scales(N_FEATURES);
	Eigen::MatrixXd coef(10, N_FEATURES);
	Eigen::VectorXd intercept(10);
	Eigen::VectorXd result(10);
	map<int, string> label;
	Eigen::Index indice;
	int match = 0;

	// lecture des informations dans le fichier csv
	ifstream f(path_modelSVC);
    lectureModelNormalisation(f, means, scales);
	lectureModel(f, coef, intercept);
	lectureLabel(f, label);

	clock_t begin=clock();

	for(int i=0; i<N_TEST_EXAMPLES; i++){
		// normalisation + mise en forme pour l'application du modele
		for(int k=0; k< N_FEATURES; k++){
			descripteur(k) = (X_test[i][k]-means(k))/scales(k);
		}

		// prediction
		result = coef*descripteur - intercept;
		result.maxCoeff(&indice);

		// evaluation prediction
		if(indice == y_test[i]){
			match++;
		}
	}

	clock_t end=clock();
	cout << "Match: " << match << endl;
	cout << "Accuracy on training platform: " << test_acc << " %\n";
	cout << "Accuracy on inference platform: " << float(match)/float(N_TEST_EXAMPLES) << " %\n";
	cout << "Prediction time: " << double(end-begin)/CLOCKS_PER_SEC << "s\n";
	return 1;
}