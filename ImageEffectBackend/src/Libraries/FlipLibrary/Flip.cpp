#include "Flip.h"
#include<bits/stdc++.h>
using namespace std;
void flipImage(vector<vector<Pixel>>& imageVector, int horizontalFlipValue, int verticalFlipValue) {
    if (horizontalFlipValue == 1) {
        // Flip horizontally
        // cout<<"Flip Horizontal\n";
        for (auto& row : imageVector) {
            reverse(row.begin(), row.end());
        }
    }

    if (verticalFlipValue == 1) {
        // cout<<"Flip Vertical\n";
        // Flip vertically
        reverse(imageVector.begin(), imageVector.end());
    }
}
