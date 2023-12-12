#include "Rotation.h"
#include <vector>
#include "../Pixel.h"
using namespace std;
void rotation(vector <vector<Pixel>> &imageVector, int rotation)
{
    if (rotation == 0)
    {
        return;
    }
    else if (rotation == 3)
    {
        int rows = imageVector.size();
        int cols = imageVector[0].size();

        vector<vector<Pixel>> rotatedImage(cols, vector<Pixel>(rows));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                rotatedImage[j][rows - 1 - i] = imageVector[i][j];
            }
        }

        imageVector = rotatedImage;
    }

    else if (rotation == 2)
    {
        int rows = imageVector.size();
        int cols = imageVector[0].size();

        vector<vector<Pixel>> rotatedImage(rows,vector<Pixel>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                rotatedImage[rows - 1 - i][cols - 1 - j] = imageVector[i][j];
            }
        }
        imageVector = rotatedImage;
    }

    else if (rotation == 1)
    {
        int rows = imageVector.size();
        int cols = imageVector[0].size();

        vector<vector<Pixel>> rotatedImage(cols, vector<Pixel>(rows));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                rotatedImage[j][i] = imageVector[i][j];
            }
        }
        imageVector = rotatedImage;
    }
}