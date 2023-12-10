#include "Contrast.h"
#include <bits/stdc++.h>


using namespace std;




void multiplyValueToPixels(vector<vector<Pixel>>& pixels, float value) {
    
    float factor=0.5+value/200*1.5;
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            pixel.r = min(255, max(0,static_cast<int>((pixel.r-128)*factor+128)));
            pixel.g = min(255, max(0,static_cast<int>((pixel.g-128)*factor + 128)));
            pixel.b = min(255, max(0,static_cast<int>((pixel.b-128)*factor + 128)));
        }
    }
    
}
