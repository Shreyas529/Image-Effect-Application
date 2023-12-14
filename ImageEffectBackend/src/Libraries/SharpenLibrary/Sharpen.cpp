#include "Sharpen.h"
#include <bits/stdc++.h>
#include "../Pixel.h"
using namespace std;

// vector<vector<double>> generateSharpenKernel(float radius) {
//     vector<vector<double>> kernel = {{0,-1,0},{-1,5,-1},{0,-1,0}};
//     double total_sum = 0.0;

//     for (int i = 0; i <= 2; ++i) 
//     {
//         for (int j = 0; j <= 2; ++j) 
//         {
//             kernel[i][j] *= exp(abs(kernel[i][j])+radius/100); 
//             total_sum += kernel[i][j];
//         }
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             kernel[i][j] /= total_sum;
//         }
//     }
    
//     return kernel;
// }

void applySharpen(vector<vector<Pixel>>& imageVector, float radius) {
    radius = 1 + radius/10.0;

    vector<vector<double>> kernel = {{0,-0.2,0},{-0.2,1.8,-0.2},{0,-0.2,0}};
    
    int height = imageVector.size();
    int width = imageVector[0].size();
    int r = 1;

    vector<vector<Pixel>> paddedImageVector(height + 2 * r, vector<Pixel>(width + 2 * r,{255,255,255}));

    for (int i = r; i < height + r; ++i) {
        for (int j = r; j < width + r; ++j) {
            paddedImageVector[i][j] = imageVector[i - r][j - r];
        }
    }

    // Apply Gaussian blur with padding
    for (int sharpens = 0; sharpens < radius; ++ sharpens)
    {
        for (int i = r; i < height + r; ++i) {
            for (int j = r; j < width + r; ++j) {
                double sumRed = 0.0, sumGreen = 0.0, sumBlue = 0.0;

                // Convolve the kernel with the pixel neighborhood
                for (int k = -r; k <= r; ++k) {
                    for (int l = -r; l <= r; ++l) {
                        sumRed += paddedImageVector[i + k][j + l].r * kernel[k + r][l + r];
                        sumGreen += paddedImageVector[i + k][j + l].g * kernel[k + r][l + r];
                        sumBlue += paddedImageVector[i + k][j + l].b * kernel[k + r][l + r];
                    }
                }

                // Update the pixel in the blurred image
                paddedImageVector[i - r][j - r].r = static_cast<int>(min(255, max(0, static_cast<int>(sumRed))));
                paddedImageVector[i - r][j - r].g = static_cast<int>(min(255, max(0, static_cast<int>(sumGreen))));
                paddedImageVector[i - r][j - r].b = static_cast<int>(min(255, max(0, static_cast<int>(sumBlue))));
            }


        }


    }
    imageVector = paddedImageVector;
}