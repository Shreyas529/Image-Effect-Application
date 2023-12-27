#include "DominantColor.h"
#include "../Pixel.h"
#include <bits/stdc++.h>
using namespace std;

void applyDominantColor(vector<vector<Pixel>> &image)
{
    unordered_map<int, int> hueFrequency;
    int s = 1;
    for (auto &row : image)
    {
        for (auto &pixel : row)
        {
            int Rvalue = pixel.r;
            int Gvalue = pixel.g;
            int Bvalue = pixel.b;
            int HueValue = getHue(Rvalue, Gvalue, Bvalue);
            HueValue = (int)(HueValue / s);
            hueFrequency[HueValue]++;
        }
    }

    int dominantHue = 0;
    int maxFrequency = 0;

    for (const auto &entry : hueFrequency)
    {
        if (entry.second > maxFrequency)
        {
            maxFrequency = entry.second;
            dominantHue = entry.first;
        }
    }
    
    for (auto &row : image)
    {
        for (auto &pixel : row)
        {
            hueToRgb(dominantHue, pixel.r, pixel.g, pixel.b);
        }
    }
}

void hueToRgb(double hue, int &red, int &green, int &blue)
{
    double c = 1.0;
    double m = 0.0;
    double x = c * (1.0 - std::fabs(std::fmod(hue / 60.0, 2.0) - 1.0));

    if (hue >= 0 && hue < 60)
    {
        red = static_cast<int>((c + m) * 255);
        green = static_cast<int>((x + m) * 255);
        blue = static_cast<int>((m) * 255);
    }
    else if (hue >= 60 && hue < 120)
    {
        red = static_cast<int>((x + m) * 255);
        green = static_cast<int>((c + m) * 255);
        blue = static_cast<int>((m) * 255);
    }
    else if (hue >= 120 && hue < 180)
    {
        red = static_cast<int>((m) * 255);
        green = static_cast<int>((c + m) * 255);
        blue = static_cast<int>((x + m) * 255);
    }
    else if (hue >= 180 && hue < 240)
    {
        red = static_cast<int>((m) * 255);
        green = static_cast<int>((x + m) * 255);
        blue = static_cast<int>((c + m) * 255);
    }
    else if (hue >= 240 && hue < 300)
    {
        red = static_cast<int>((x + m) * 255);
        green = static_cast<int>((m) * 255);
        blue = static_cast<int>((c + m) * 255);
    }
    else
    {
        red = static_cast<int>((c + m) * 255);
        green = static_cast<int>((m) * 255);
        blue = static_cast<int>((x + m) * 255);
    }
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
