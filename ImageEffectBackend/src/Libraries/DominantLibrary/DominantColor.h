#ifndef DOMINANT_COLOR_H
#define DOMINANT_COLOR_H
#include "../Pixel.h"
#include <vector>
using namespace std;
void applyDominantColor(vector<vector<Pixel>> &);
int getHue(int, int, int);
int getSaturation(int, int, int);
void hueSaturationToRgb(double, double, int &, int &, int &);

void clamp(int &);

#endif
