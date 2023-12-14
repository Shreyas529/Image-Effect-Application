#include "HueSaturation.h"
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

void rgbToHsv(int r, int g, int b, double &h, double &s)
{
    int R = r / 255.0;
    int G = g / 255.0;
    int B = b / 255.0;

    double cmax = max(R, G, B);
    double cmin = min(R, G, B);
    double diff = cmax - cmin;

    if (cmax == cmin)
    {
        h = 0;
    }

    else if (cmax == R)
    {
        h = fmod(60 * ((G - B) / diff) + 360, 360);
    }

    else if (cmax == G)
    {
        h = fmod(60 * ((B - R) / diff) + 120, 360);
    }

    else if (cmax == B)
    {
        h = fmod(60 * ((R - G) / diff) + 240, 360);
    }

    if (cmax == 0)
        s = 0;
    else
        s = (diff / cmax) * 100;
}

void hsvToRgb(double h, double s, int &r, int &g, int &b)
{
    h = h / 60.0;
    s = s / 100.0;

    double c = s * (1 - std::abs(2 * h - 1));
    double x = c * (1 - std::abs(fmod(h, 2) - 1));
    double m = 1 - s;

    double rp, gp, bp;

    if (h >= 0 && h < 1)
    {
        rp = c;
        gp = x;
        bp = 0;
    }
    else if (h >= 1 && h < 2)
    {
        rp = x;
        gp = c;
        bp = 0;
    }
    else if (h >= 2 && h < 3)
    {
        rp = 0;
        gp = c;
        bp = x;
    }
    else if (h >= 3 && h < 4)
    {
        rp = 0;
        gp = x;
        bp = c;
    }
    else if (h >= 4 && h < 5)
    {
        rp = x;
        gp = 0;
        bp = c;
    }
    else
    {
        rp = c;
        gp = 0;
        bp = x;
    }

    r = static_cast<int>((rp + m) * 255);
    g = static_cast<int>((gp + m) * 255);
    b = static_cast<int>((bp + m) * 255);
}

void applyHueSaturation(vector<vector<Pixel>> &imageData, float saturationAmount, float hueAmount)
{

    for (auto &row : imageData)
    {
        for (auto &pixel : row)
        {
            double h, s;
            rgbToHsv(pixel.r, pixel.g, pixel.b, h, s);
            h = fmod(h + hueAmount, 360.0);
            s = max(0.0, min(100.0, s + saturationAmount));
            hsvToRgb(h, s, pixel.r, pixel.g, pixel.b);
        }
    }
}