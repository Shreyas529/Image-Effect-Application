#include "Sharpen.h"
#include <bits/stdc++.h>
#include "../Pixel.h"
using namespace std;

void sharpen(vector <vector<Pixel>> &imageVector, float amount)
{
    vector <vector <int>> sharpen_kernel = {{0,-1,0},{-1,5,-1},{0,-1,0}};


    int i, j, m, n;
    int length = imageVector[0].size();
    int height = imageVector.size();

    vector <vector<Pixel>> outputMatrix;

    for (i = 0; i < length - 2; ++i) {
        for (j = 0; j < height - 2; ++j) {
            int sum = 0;
            float sumRed = 0, sumGreen = 0, sumBlue = 0;


            // Iterate through each element of the 3x3 filter
            for (int k = 0; k <= 3; ++k) {
                for (int l = 0; l <= 3; ++l) {
                    sumRed += imageVector[i + m][j + l].r * sharpen_kernel[k][l] * amount;
                    sumGreen += imageVector[i + m][j + l].g * sharpen_kernel[k][l] * amount;
                    sumBlue += imageVector[i + m][j + l].b * sharpen_kernel[k][l] * amount;
                }
            }

            imageVector[i][j].r = static_cast<int>(min(255,max(0,(int)sumRed)));
            imageVector[i][j].g = static_cast<int>(min(255,max(0,(int)sumGreen)));
            imageVector[i][j].b = static_cast<int>(min(255,max(0,(int)sumBlue)));
        }
    }
}