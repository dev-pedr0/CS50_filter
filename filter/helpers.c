#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float media = ((blue+red+green)/3);

            if(media > 255)
            {
                media = 255;
            }

            image[i][j].rgbtBlue = round(media);
            image[i][j].rgbtGreen = round(media);
            image[i][j].rgbtRed = round(media);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float sblue = (red*0.272)+(green*0.534)+(blue*0.131);
            float sred = (red*0.393)+(green*0.769)+(blue*0.189);
            float sgreen = (red*0.349)+(green*0.686)+(blue*0.168);
            if (sblue > 255)
            {
                sblue = 255;
            }
            if (sred > 255)
            {
                sred = 255;
            }
            if (sgreen > 255)
            {
                sgreen = 255;
            }
            image[i][j].rgbtBlue = round(sblue);
            image[i][j].rgbtGreen = round(sgreen);
            image[i][j].rgbtRed = round(sred);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < ((width/2)); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width-1)-j];
            image[i][width-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            int counter = 1;
            if (i-1 >= 0 && j-1 >= 0)
            {
                blue = blue + image[i-1][j-1].rgbtBlue;
                red = red + image[i-1][j-1].rgbtRed;
                green = green + image[i-1][j-1].rgbtGreen;
                counter ++;
            }
            if (i-1 >= 0)
            {
                blue = blue + image[i-1][j].rgbtBlue;
                red = red + image[i-1][j].rgbtRed;
                green = green + image[i-1][j].rgbtGreen;
                counter ++;
            }
            if (i-1 >= 0 && j+1 < width)
            {
                blue = blue + image[i-1][j+1].rgbtBlue;
                red = red + image[i-1][j+1].rgbtRed;
                green = green + image[i-1][j+1].rgbtGreen;
                counter ++;
            }
            if (j-1 >= 0)
            {
                blue = blue + image[i][j-1].rgbtBlue;
                red = red + image[i][j-1].rgbtRed;
                green = green + image[i][j-1].rgbtGreen;
                counter ++;
            }
            if (j+1 < width)
            {
                blue = blue + image[i][j+1].rgbtBlue;
                red = red + image[i][j+1].rgbtRed;
                green = green + image[i][j+1].rgbtGreen;
                counter ++;
            }
            if (i+1 < height && j-1 >= 0)
            {
                blue = blue + image[i+1][j-1].rgbtBlue;
                red = red + image[i+1][j-1].rgbtRed;
                green = green + image[i+1][j-1].rgbtGreen;
                counter ++;
            }
            if (i+1 < height)
            {
                blue = blue + image[i+1][j].rgbtBlue;
                red = red + image[i+1][j].rgbtRed;
                green = green + image[i+1][j].rgbtGreen;
                counter ++;
            }
            if (i+1 < height && j+1 < width)
            {
                blue = blue + image[i+1][j+1].rgbtBlue;
                red = red + image[i+1][j+1].rgbtRed;
                green = green + image[i+1][j+1].rgbtGreen;
                counter ++;
            }
            image[i][j].rgbtBlue = round(blue/counter);
            image[i][j].rgbtRed = round(red/counter);
            image[i][j].rgbtGreen = round(green/counter);
        }
    }
    return;
}
