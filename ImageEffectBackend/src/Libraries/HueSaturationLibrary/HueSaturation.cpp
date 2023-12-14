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
    // h = fmod(h, 360.0);
    // s = max(0.0, min(100.0, s));

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

void applyHueSaturation(std::vector<std::vector<Pixel>>& imageData, float saturationSliderValue, float hueSliderValue) {
    double hueAngle = (hueSliderValue / 100.0) * 180.0; // Convert slider value to degrees

    // Hue rotation matrix
    double cosA = cos(hueAngle * M_PI / 180.0);
    double sinA = sin(hueAngle * M_PI / 180.0);

    double hueRotationMatrix[9] = {
        cosA, -sinA, 0,
        sinA, cosA, 0,
        0, 0, 1
    };

    // Apply hue rotation and saturation change to each pixel
    for (auto& row : imageData) {
        for (auto& pixel : row) {
            double r = pixel.r / 255.0;
            double g = pixel.g / 255.0;
            double b = pixel.b / 255.0;

            // Calculate luminance to differentiate chromatic and grayscale components
            double luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b;

            // Check if the pixel is black, white, or gray
            bool isGrayScale = luminance < 0.25 || luminance > 0.95;
            bool isChromatic = !isGrayScale;

            if (isChromatic) {
                // Apply hue rotation only to chromatic components
                double newR = r * hueRotationMatrix[0] + g * hueRotationMatrix[1] + b * hueRotationMatrix[2];
                double newG = r * hueRotationMatrix[3] + g * hueRotationMatrix[4] + b * hueRotationMatrix[5];
                double newB = r * hueRotationMatrix[6] + g * hueRotationMatrix[7] + b * hueRotationMatrix[8];

                // Saturate chromatic components
                double intensity = 0.3 * r + 0.59 * g + 0.11 * b; // Calculate intensity

                newR = intensity + saturationSliderValue / 100.0 * (newR - intensity);
                newG = intensity + saturationSliderValue / 100.0 * (newG - intensity);
                newB = intensity + saturationSliderValue / 100.0 * (newB - intensity);

                // Update pixel values
                pixel.r = static_cast<unsigned char>(std::clamp(newR * 255.0, 0.0, 255.0));
                pixel.g = static_cast<unsigned char>(std::clamp(newG * 255.0, 0.0, 255.0));
                pixel.b = static_cast<unsigned char>(std::clamp(newB * 255.0, 0.0, 255.0));
            }
        }
    }
}




