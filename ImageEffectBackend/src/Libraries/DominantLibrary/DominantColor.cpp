#include "DominantColor.h"
#include "../Pixel.h"
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

void clamp(int &value) {
    value = (value < 0) ? 0 : ((value > 255) ? 255 : value);
}

void applyDominantColor(vector<vector<Pixel>> &image)
{
    unordered_map<int, unordered_map<int, int>> hueSaturationFrequency;
    int s = 1;
    for (auto &row : image)
    {
        for (auto &pixel : row)
        {
            int Rvalue = pixel.r;
            int Gvalue = pixel.g;
            int Bvalue = pixel.b;
            int HueValue = getHue(Rvalue, Gvalue, Bvalue);
            int SaturationValue = getSaturation(Rvalue, Gvalue, Bvalue);

            HueValue = (int)(HueValue / s);
            SaturationValue = (int)(SaturationValue / s);

            hueSaturationFrequency[HueValue][SaturationValue]++;
        }
    }

    int dominantHue = 0;
    int dominantSaturation = 0;
    int maxFrequency = 0;

    for (const auto &hueEntry : hueSaturationFrequency)
    {
        for (const auto &saturationEntry : hueEntry.second)
        {
            if (saturationEntry.second > maxFrequency)
            {
                maxFrequency = saturationEntry.second;
                dominantHue = hueEntry.first;
                dominantSaturation = saturationEntry.first;
            }
        }
    }

    for (auto &row : image)
    {
        for (auto &pixel : row)
        {
            hueSaturationToRgb(dominantHue, dominantSaturation, pixel.r, pixel.g, pixel.b);
            
        }
    }
    for(auto &row:image)
    {
        for(auto &pixel : row)
        {
            clamp(pixel.r);
            clamp(pixel.g);
            clamp(pixel.b);
        }
    }
}

void hueSaturationToRgb(double hue, double saturation, int &red, int &green, int &blue)
{
    double H = hue;
    double S = saturation / 100.0;
    double V = 1.0; // Assuming max brightness for simplicity

    double C = V * S;
    double X = C * (1 - abs(fmod(H / 60.0, 2.0) - 1));
    double m = V - C;

    double R, G, B;

    if (H >= 0 && H < 60) {
        R = C;
        G = X;
        B = 0;
    } else if (H >= 60 && H < 120) {
        R = X;
        G = C;
        B = 0;
    } else if (H >= 120 && H < 180) {
        R = 0;
        G = C;
        B = X;
    } else if (H >= 180 && H < 240) {
        R = 0;
        G = X;
        B = C;
    } else if (H >= 240 && H < 300) {
        R = X;
        G = 0;
        B = C;
    } else {
        R = C;
        G = 0;
        B = X;
    }

    red = static_cast<int>((R + m) * 255);
    green = static_cast<int>((G + m) * 255);
    blue = static_cast<int>((B + m) * 255);
}

int getSaturation(int red, int green, int blue)
{
    int maxVal = max(max(red, green), blue);
    int minVal = min(min(red, green), blue);

    if (maxVal == 0)
        return 0;
    else
        return ((maxVal - minVal) * 100) / maxVal;
}

int getHue(int red, int green, int blue)
{
    float minVal = std::min(std::min(red, green), blue);
    float maxVal = std::max(std::max(red, green), blue);

    if (minVal == maxVal)
    {
        return 0;
    }

    float hue = 0.0f;
    if (maxVal == red)
    {
        hue = (green - blue) / (maxVal - minVal);
    }
    else if (maxVal == green)
    {
        hue = 2.0f + (blue - red) / (maxVal - minVal);
    }
    else
    {
        hue = 4.0f + (red - green) / (maxVal - minVal);
    }

    hue *= 60.0f;
    if (hue < 0)
        hue += 360.0f;

    return static_cast<int>(std::round(hue));
}
