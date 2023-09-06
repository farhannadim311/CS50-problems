#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed =  avg;
            image[i][j].rgbtGreen =  avg;
            image[i][j].rgbtBlue =  avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepia1[height][width];
    float sepia2[height][width];
    float sepia3[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepia1[i][j] = round((0.393 * (float)image[i][j].rgbtRed + 0.769 * (float)image[i][j].rgbtGreen + 0.189 * (float)image[i][j].rgbtBlue));
            if (sepia1[i][j] > 255)
            {
                sepia1[i][j] = 255;
            }
            sepia2[i][j] = round((0.349 * (float)image[i][j].rgbtRed + 0.686 * (float)image[i][j].rgbtGreen + 0.168 * (float)image[i][j].rgbtBlue));
            if (sepia2[i][j] > 255)
            {
                sepia2[i][j] = 255;
            }
            sepia3[i][j] = round((0.272 * (float) image[i][j].rgbtRed + 0.534 * (float) image[i][j].rgbtGreen +
                                  0.131 * (float) image[i][j].rgbtBlue));
            if (sepia3[i][j] > 255)
            {
                sepia3[i][j] = 255;
            }
            image[i][j].rgbtRed = sepia1[i][j];
            image[i][j].rgbtGreen = sepia2[i][j];
            image[i][j].rgbtBlue = sepia3[i][j];
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflect[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            reflect[i][j].rgbtRed = image[i][(width - 1) - j].rgbtRed;
            reflect[i][j].rgbtGreen = image[i][(width - 1) - j].rgbtGreen;
            reflect[i][j].rgbtBlue = image[i][(width - 1) - j].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = reflect[i][j].rgbtRed;
            image[i][j].rgbtBlue = reflect[i][j].rgbtBlue;
            image[i][j].rgbtGreen = reflect[i][j].rgbtGreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float blurR[height][width];
    float blurG[height][width];
    float blurB[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 && i == 0)
            {
                for (int a = 0; a <= 1; a++)
                {
                    for (int b = 0; b <= 1; b++)
                    {
                        blurR[i][j] = (float) image[i + a][j + b].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + a][j + b].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + a][j + b].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 4.0);
                blurG[i][j] = round((float) blurG[i][j] / 4.0);
                blurB[i][j] = round((float) blurB[i][j] / 4.0);
            }
            if ((j > 0 && j < (width - 1)) && i == 0)
            {
                for (int c = 0; c <= 1; c++)
                {
                    for (int d = -1; d <= 1; d++)
                    {
                        blurR[i][j] = (float) image[i + c][j + d].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + c][j + d].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + c][j + d].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 6.0);
                blurG[i][j] = round((float) blurG[i][j] / 6.0);
                blurB[i][j] = round((float) blurB[i][j] / 6.0);
            }
            if (j == (width - 1) && i == 0)
            {
                for (int e = 0; e <= 1; e++)
                {
                    for (int f = -1; f <= 0; f++)
                    {
                        blurR[i][j] = (float) image[i + e][j + f].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + e][j + f].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + e][j + f].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 4.0);
                blurG[i][j] = round((float) blurG[i][j] / 4.0);
                blurB[i][j] = round((float) blurB[i][j] / 4.0);
            }
            if (j == 0 && (i > 0 && i < (height - 1)))
            {
                for (int g = -1; g <= 1; g++)
                {
                    for (int h = 0; h <= 1; h++)
                    {
                        blurR[i][j] = (float) image[i + g][j + h].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + g][j + h].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + g][j + h].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 6.0);
                blurG[i][j] = round((float) blurG[i][j] / 6.0);
                blurB[i][j] = round((float) blurB[i][j] / 6.0);
            }
            if ((j > 0 && j < (width - 1)) && (i > 0 && i < (height - 1)))
            {
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        blurR[i][j] = (float) image[i + k][j + l].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + k][j + l].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + k][j + l].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 9.0);
                blurG[i][j] = round((float) blurG[i][j] / 9.0);
                blurB[i][j] = round((float) blurB[i][j] / 9.0);
            }
            if (j == (width - 1) && (i > 0 && i < (height - 1)))
            {
                for (int m = -1; m <= 1; m++)
                {
                    for (int n = -1; n <= 0; n++)
                    {
                        blurR[i][j] = (float) image[i + m][j + n].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + m][j + n].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + m][j + n].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 6.0);
                blurG[i][j] = round((float) blurG[i][j] / 6.0);
                blurB[i][j] = round((float) blurB[i][j] / 6.0);
            }
            if (j == 0 && i == (height - 1))
            {
                for (int o = -1; o <= 0; o++)
                {
                    for (int p = 0; p <= 1; p++)
                    {
                        blurR[i][j] = (float) image[i + o][j + p].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + o][j + p].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + o][j + p].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 4.0);
                blurG[i][j] = round((float) blurG[i][j] / 4.0);
                blurB[i][j] = round((float) blurB[i][j] / 4.0);
            }
            if ((j > 0 && j < (width - 1)) && (i == (height - 1)))
            {
                for (int q = -1; q <= 0; q++)
                {
                    for (int r = -1; r <= 1; r++)
                    {
                        blurR[i][j] = (float) image[i + q][j + r].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + q][j + r].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + q][j + r].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 6.0);
                blurG[i][j] = round((float) blurG[i][j] / 6.0);
                blurB[i][j] = round((float) blurB[i][j] / 6.0);
            }
            if (i == (height - 1) && j == (width - 1))
            {
                for (int s = -1; s <= 0; s++)
                {
                    for (int t = -1; t <= 0; t++)
                    {
                        blurR[i][j] = (float) image[i + s][j + t].rgbtRed + blurR[i][j];
                        blurG[i][j] = (float) image[i + s][j + t].rgbtGreen + blurG[i][j];
                        blurB[i][j] = (float) image[i + s][j + t].rgbtBlue + blurB[i][j];
                    }
                }
                blurR[i][j] = round((float) blurR[i][j] / 4.0);
                blurG[i][j] = round((float) blurG[i][j] / 4.0);
                blurB[i][j] = round((float) blurB[i][j] / 4.0);
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = blurR[i][j];
            image[i][j].rgbtGreen = blurG[i][j];
            image[i][j].rgbtBlue = blurB[i][j];
        }
    }
    return;
}
