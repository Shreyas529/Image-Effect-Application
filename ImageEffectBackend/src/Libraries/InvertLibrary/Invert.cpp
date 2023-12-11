#include "Invert.h"
#include <vector>
using namespace std;
void inversion(vector<vector<Pixel>> &pixels){   //invert the image
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            pixel.r = 255 - pixel.r;
            pixel.g = 255 - pixel.g;
            pixel.b = 255 - pixel.b;
        }
    }
}
