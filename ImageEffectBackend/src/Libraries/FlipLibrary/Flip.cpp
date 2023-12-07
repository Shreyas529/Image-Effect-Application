#include "Flip.h"
#include "../Pixel.h"
#include <bits/stdc++.h>
using namespace std;
void flipImage(vector<vector<Pixel>> &Image)
{
    for(auto &row : Image)
    {
        reverse(row.begin() , row.end());
    }
}