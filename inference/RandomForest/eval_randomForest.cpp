#include <iostream>
#include <fstream>
#include "../utils/utils_function.h"
#include "codeRandomForest.h"
#include "test_dataset.h"
#include <complex>
#include <map>

using namespace std;

int main(int argc, char** argv){
    //chemin vers le modele
	string path_modelRandomForest = "modelRandomForest.csv";

    //declaration des variables utiles
    double means[N_FEATURES];
    double scales[N_FEATURES];
    ifstream f(path_modelRandomForest);
    lectureModelNormalisation(f, means, scales);

    double mu[N_FEATURES/2];
    double sigma[N_FEATURES/2];

    int match=0;
	int class_predicted;
	float max_score=0;
	clock_t begin=clock();

    for(int i=0; i<N_TEST_EXAMPLES; i++){
        for(int j=0; j<N_FEATURES/2; j++){
            mu[j] = X_test[i][j];
            sigma[j] = X_test[i][j+N_FEATURES/2];
        }
        normalisation(mu, sigma, means, scales);
        class_predicted = randomForest(mu, sigma);

        if(class_predicted == y_test[i]){
            match++;
        }
    }
    clock_t end=clock();
    cout << endl << endl;
	std::cout << "Match: " << match << std::endl;
	std::cout << "Accuracy on training platform: " << test_acc << " %\n";
	std::cout << "Accuracy on inference platform: " << float(match)/float(N_TEST_EXAMPLES) << " %\n";
	std::cout << "Prediction time: " << double(end-begin)/CLOCKS_PER_SEC << "s\n";
	return 1;
}