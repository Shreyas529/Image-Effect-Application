#include "Sepia.h"
using namespace std;
#include <bits/stdc++.h>
void applySepia(vector<vector<Pixel>>&imageVector)
{
    for(auto & row:imageVector)
    {
        for(auto &pixel:row)
        {
            int newRed = static_cast<int>(0.393 * pixel.r + 0.769 * pixel.g + 0.189 * pixel.b);
            int newGreen = static_cast<int>(0.349 * pixel.r + 0.686 * pixel.g + 0.168 * pixel.b);
            int newBlue = static_cast<int>(0.272 * pixel.r + 0.534 * pixel.g + 0.131 * pixel.b);

            // Clip values to the valid range [0, 255]
            pixel.r = min(255, max(0, newRed));
            pixel.g = min(255, max(0, newGreen));
            pixel.b = min(255, max(0, newBlue));
        }
    }
}