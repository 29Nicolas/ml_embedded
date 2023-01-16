#ifndef __EXTRACTION_DESCRIPTEUR_H__
#define __EXTRACTION_DESCRIPTEUR_H__

#include <iostream>
#include <fstream>
#include "constants.h"
#include "fft_utils.h"
#include <complex>
#include <map>
using namespace std;

int read32Bits(ifstream &file_s);
int readNBits(ifstream &file_s, int n);
int readSample(ifstream &file_s);
void extraction_descripteur(string file_name, double mu[], double sigma[]);

#endif