#include <iostream>
#include <fstream>
#include "../utils/extraction_descripteur.h"
#include "../utils/utils_function.h"
#include "codeRandomForest.h"
#include <complex>
#include <map>

using namespace std;


int main(int argc, char** argv){

	//chemin vers les echantillons de musique et les modeles
	string file_path = "../../archive/genres/";
	string path_modelDecisionTree = "modelRandomForest.csv";
	
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
    
    //extraction des descripteurs (methode commune pour tous les modeles)
    extraction_descripteur(file_path, mu, sigma);
    
    // Decision Tree
    ifstream f(path_modelDecisionTree);
    lectureModelNormalisation(f, means, scales);
    normalisation(mu, sigma, means, scales);
    int a = randomForest(mu, sigma);
}