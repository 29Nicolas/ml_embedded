#include <iostream>
#include "code.h"
using namespace std; 

int main(){
    double mu[512]; 
    double sigma[512];
    int a = decision_tree(mu, sigma);
    cout << a << endl;
}