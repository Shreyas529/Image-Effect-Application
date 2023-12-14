#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include "HueSaturation.h"
using namespace std;

void applyHueSaturation(std::vector<std::vector<Pixel>>& image, float saturationValue, float hueValue) {
    // Define constants
    const float PI = 3.14159265f;
    const float angleToRadians = PI / 180.0f;

    // Calculate angle adjustment for hue
    float hueAngle = (hueValue / 100.0f) * 360.0f - 180.0f;

    // Calculate saturation factor
    float saturationFactor = saturationValue / 100.0f;

    // Iterate through each pixel in the image
    for (auto& row : image) {
        for (auto& pixel : row) {
            // Convert RGB to HSL color space
            float r = pixel.r / 255.0f;
            float g = pixel.g / 255.0f;
            float b = pixel.b / 255.0f;

            float cmax = fmaxf(fmaxf(r, g), b);
            float cmin = fminf(fminf(r, g), b);
            float delta = cmax - cmin;

            float hue = 0.0f;
            if (delta != 0) {
                if (cmax == r) {
                    hue = 60.0f * fmodf((g - b) / delta, 6.0f);
                } else if (cmax == g) {
                    hue = 60.0f * (((b - r) / delta) + 2.0f);
                } else {
                    hue = 60.0f * (((r - g) / delta) + 4.0f);
                }
            }

            if (hue < 0.0f) {
                hue += 360.0f;
            }

            float lightness = (cmax + cmin) / 2.0f;
            float saturation = delta == 0 ? 0 : delta / (1 - fabsf(2 * lightness - 1));

            // Apply hue and saturation adjustments
            hue += hueAngle;
            if (hue < 0.0f) {
                hue += 360.0f;
            }

            saturation *= saturationFactor;
            if (saturation < 0.0f) {
                saturation = 0.0f;
            } else if (saturation > 1.0f) {
                saturation = 1.0f;
            }

            // Convert back to RGB color space
            float chroma = (1 - fabsf(2 * lightness - 1)) * saturation;
            float huePrime = hue / 60.0f;
            float x = chroma * (1 - fabsf(fmodf(huePrime, 2.0f) - 1));
            float m = lightness - chroma / 2.0f;

            float rp, gp, bp;
            if (huePrime >= 0 && huePrime < 1) {
                rp = chroma;
                gp = x;
                bp = 0;
            } else if (huePrime >= 1 && huePrime < 2) {
                rp = x;
                gp = chroma;
                bp = 0;
            } else if (huePrime >= 2 && huePrime < 3) {
                rp = 0;
                gp = chroma;
                bp = x;
            } else if (huePrime >= 3 && huePrime < 4) {
                rp = 0;
                gp = x;
                bp = chroma;
            } else if (huePrime >= 4 && huePrime < 5) {
                rp = x;
                gp = 0;
                bp = chroma;
            } else {
                rp = chroma;
                gp = 0;
                bp = x;
            }

            pixel.r = static_cast<int>((rp + m) * 255.0f);
            pixel.g = static_cast<int>((gp + m) * 255.0f);
            pixel.b = static_cast<int>((bp + m) * 255.0f);
        }
    }
}









