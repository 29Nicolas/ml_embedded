#ifndef __UTILS_FUNCTION_H__
#define __UTILS_FUNCTION_H__
#include <iostream>
#include <fstream>
#include <complex>
#include <map>
#include "constants.h"

using namespace std;

void lectureModelNormalisation(ifstream &f, double means[], double scales[]);
void normalisation(double mu[], double sigma[], double means[], double scales[]);

#endif