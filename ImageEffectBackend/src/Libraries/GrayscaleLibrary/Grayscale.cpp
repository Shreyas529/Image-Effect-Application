#include "Grayscale.h"
#include "../Pixel.h"
#include <bits/stdc++.h>
using namespace std;

void convertToGrayscale(vector<vector<Pixel>>& image) {
    for (auto& row : image) {
        for (auto& pixel : row) {
            // Calculate the average of RGB values
            int average = (pixel.r + pixel.g + pixel.b) / 3;

            // Set the RGB values to the average to create grayscale effect
            pixel.r = average;
            pixel.g = average;
            pixel.b = average;
        }
    }
}