#include <iostream>
#include <string>
#include "code.h"
#include "lecture.h"
#include "constants.h"

using namespace std;

void normalisation(double mu[], double sigma[], double means[], double scales[]){
    for(int i = 0; i<N; i++){
        mu[i] = (mu[i]-means[i])/scales[i];
        sigma[i+2*N] = (sigma[i+2*N]-means[i+2*N])/scales[i+2*N];
    }
}

int main(){
    string model = "../model/model_DecisionTreeClassifier_ml.csv";
	string file_path = "../archive/genres/blues/blues.00000.au";

	double mu[N];
	double sigma[N];
    double means[2*N]; 
    double scales[2*N];
	extraction_descripteur(file_path, mu, sigma);
    lecture_modelDecisionTree(model, means, scales);

    normalisation(mu, sigma, means, scales);

	int a = decision_tree(mu, sigma);
    cout << a << endl;
	
}