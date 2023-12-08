#ifndef GAUSSIAN_BLUR_H
#define GAUSSIAN_BLUR_H
#include "../Pixel.h"
#include <vector>
using namespace std;
void applyGaussianBlur(vector<vector<Pixel>>&imageVector,float radius);
vector<vector<double>> generateGaussianKernel(int radius, double sigma);
#endif