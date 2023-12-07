#include "Brightness.h"
#include <bits/stdc++.h>


using namespace std;




vector<vector<Pixel>>& addValueToPixels(vector<vector<Pixel>>& pixels, float value) {
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            pixel.r = min(255, static_cast<int>(pixel.r + value));
            pixel.g = min(255, static_cast<int>(pixel.g + value));
            pixel.b = min(255, static_cast<int>(pixel.b + value));
        }
    }
    return pixels;
}
