#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include "HueSaturation.h"
using namespace std;

void rgbToHsv(int r, int g, int b, double &h, double &s) {
    double R = r / 255.0;
    double G = g / 255.0;
    double B = b / 255.0;

    double cmax = max(R, max(G, B));
    double cmin = min(R, min(G, B));
    double diff = cmax - cmin;

    if (cmax == cmin) {
        h = 0;
    } else if (cmax == R) {
        h = fmod(60 * ((G - B) / diff) + 360, 360);
    } else if (cmax == G) {
        h = fmod(60 * ((B - R) / diff) + 120, 360);
    } else if (cmax == B) {
        h = fmod(60 * ((R - G) / diff) + 240, 360);
    }

    if (cmax == 0) {
        s = 0;
    } else {
        s = (diff / cmax) * 100;
    }
}

void hsvToRgb(double h, double s, int &r, int &g, int &b) {
    h = fmod(h, 360.0);
    s = max(0.0, min(100.0, s));

    double C = s / 100.0;
    double X = C * (1 - abs(fmod(h / 60.0, 2) - 1));
    double m = (1 - C);

    double Rp = 0, Gp = 0, Bp = 0;

    if (h >= 0 && h < 60) {
        Rp = C;
        Gp = X;
    } else if (h >= 60 && h < 120) {
        Rp = X;
        Gp = C;
    } else if (h >= 120 && h < 180) {
        Gp = C;
        Bp = X;
    } else if (h >= 180 && h < 240) {
        Gp = X;
        Bp = C;
    } else if (h >= 240 && h < 300) {
        Rp = X;
        Bp = C;
    } else if (h >= 300 && h < 360) {
        Rp = C;
        Bp = X;
    }

    r = static_cast<int>((Rp + m) * 255);
    g = static_cast<int>((Gp + m) * 255);
    b = static_cast<int>((Bp + m) * 255);
}

void applyHueSaturation(vector<vector<Pixel>> &imageData, float saturationAmount, float hueAmount) {
    saturationAmount = saturationAmount;    //range : 0 - 100
    hueAmount =  hueAmount;                 //range : 0 - 100
    for (auto &row : imageData) {
        for (auto &pixel : row) {
            double h, s;
            rgbToHsv(pixel.r, pixel.g, pixel.b, h, s);

            // Adjusting hue and saturation subtly
            h = fmod(h + hueAmount, 360.0);
            s = max(0.0, min(100.0, s + saturationAmount));

            hsvToRgb(h, s, pixel.r, pixel.g, pixel.b);
        }
    }
}