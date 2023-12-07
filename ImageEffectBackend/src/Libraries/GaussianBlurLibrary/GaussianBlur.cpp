#include "GaussianBlur.h"
#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> generateGaussianKernel(int radius, double sigma) {
    int size = 2 * radius + 1;
    vector<vector<double>> kernel(size, vector<double>(size));

    double sum = 0.0;
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            kernel[i + radius][j + radius] = std::exp(-(i * i + j * j) / (2 * sigma * sigma));
            sum += kernel[i + radius][j + radius];
        }radius
    }
    // Normalize the kernel
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            kernel[i][j] /= sum;
        }
    }

    return kernel;
}
void applyGaussianBlur(vector<vector<Pixel>>&imageVector,float radius)
{
    double sigma=radius/3; // the same value as opencv
    vector<vector<double>> kernel=generateGaussianKernel(static_cast<int>(radius),sigma);
    int height=imageVector.size();
    int width=imageVector[0].size();
    int r=(int)radius;
    for (int i = r; i < height - r; ++i) {
        for (int j = r; j < width - r; ++j) {
            double sumRed = 0.0, sumGreen = 0.0, sumBlue = 0.0;

            // Convolve the kernel with the pixel neighborhood
            for (int k = -r; k <= r; ++k) {
                for (int l = -r; l <= r; ++l) {
                    sumRed += imageVector[i + k][j + l].r * kernel[k + r][l + r];
                    sumGreen += imageVector[i + k][j + l].g * kernel[k + r][l + r];
                    sumBlue += imageVector[i + k][j + l].b * kernel[k + r][l + r];
                }
            }

            // Update the pixel in the blurred image

            imageVector[i][j].r = static_cast<int>(min(255,max(0,(int)sumRed)));
            imageVector[i][j].g = static_cast<int>(min(255,max(0,(int)sumGreen)));
            imageVector[i][j].b = static_cast<int>(min(255,max(0,(int)sumBlue)));
        }
    }    
}