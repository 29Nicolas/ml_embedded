#include "utils_function.h"

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

int maxTableau(double tableau[10]){
	double max = tableau[0];
	int index_max = 0;
	for(int i=0;i<10;i++){
		if(max<tableau[i]){
			index_max = i;
			max = tableau[i];
		}
	}
	return index_max;
}