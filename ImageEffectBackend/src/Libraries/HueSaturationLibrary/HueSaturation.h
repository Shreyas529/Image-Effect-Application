#ifndef HUE_SATURATION_H
#define HUE_SATURATION_H
#include "../Pixel.h"
#include <vector>
void applyHueSaturation(std::vector<std::vector<Pixel>> &, float, float);
void rgbToHsv(int , int , int , double &, double &);
void hsvToRgb(double , double , int &, int &, int &);
#endif