#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set pointer to individual pixel RGB struct (helps shorten code below)
            RGBTRIPLE *pixel = &image[i][j];
            // cant use *pixel.rgbtBlue... need to use (*pixel).rgbtBlue
            int average = round(((*pixel).rgbtBlue + (*pixel).rgbtGreen + (*pixel).rgbtRed) / 3.0);
            (*pixel).rgbtBlue = (int) average;
            (*pixel).rgbtGreen = (int) average;
            (*pixel).rgbtRed = (int) average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // reverse width array
        int n = width;
        int end = width - 1;

        for (int j = 0; j < n / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][end];
            image[i][end] = tmp;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // make a copy of the image
    RGBTRIPLE pixel[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixel[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        // for every pixel...
        for (int j = 0; j < width; j++)
        {
            int counter = 0, red = 0, green = 0, blue = 0;
            // current pixel
            red += pixel[i][j].rgbtRed;
            green += pixel[i][j].rgbtGreen;
            blue += pixel[i][j].rgbtBlue;
            counter++;

            // check if pixel above and to the left exists
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += pixel[i - 1][j - 1].rgbtRed;
                green += pixel[i - 1][j - 1].rgbtGreen;
                blue += pixel[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            // pixel directly above
            if (i - 1 >= 0 && j >= 0)
            {
                red += pixel[i - 1][j].rgbtRed;
                green += pixel[i - 1][j].rgbtGreen;
                blue += pixel[i - 1][j].rgbtBlue;
                counter++;
            }
            // pixel above and to the right
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += pixel[i - 1][j + 1].rgbtRed;
                green += pixel[i - 1][j + 1].rgbtGreen;
                blue += pixel[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            // pixel to the left
            if (j - 1 >= 0)
            {
                red += pixel[i][j - 1].rgbtRed;
                green += pixel[i][j - 1].rgbtGreen;
                blue += pixel[i][j - 1].rgbtBlue;
                counter++;
            }
            // pixel to the right
            if (j + 1 < width)
            {
                red += pixel[i][j + 1].rgbtRed;
                green += pixel[i][j + 1].rgbtGreen;
                blue += pixel[i][j + 1].rgbtBlue;
                counter++;
            }
            // pixel below and to the left
            if (i + 1 < height && j - 1 >= 0)
            {
                red += pixel[i + 1][j - 1].rgbtRed;
                green += pixel[i + 1][j - 1].rgbtGreen;
                blue += pixel[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            // pixel directly below
            if (i + 1 < height && j >= 0)
            {
                red += pixel[i + 1][j].rgbtRed;
                green += pixel[i + 1][j].rgbtGreen;
                blue += pixel[i + 1][j].rgbtBlue;
                counter++;
            }
            // pixel below and to the right
            if (i + 1 < height && j + 1 < width)
            {
                red += pixel[i + 1][j + 1].rgbtRed;
                green += pixel[i + 1][j + 1].rgbtGreen;
                blue += pixel[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxBlue = 0;
            int gyBlue = 0;
            int gxGreen = 0;
            int gyGreen = 0;
            int gxRed = 0;
            int gyRed = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    gxBlue += image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1];
                    gyBlue += image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1];
                    gxGreen += image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1];
                    gyGreen += image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1];
                    gxRed += image[i + r][j + c].rgbtRed * gx[r + 1][c + 1];
                    gyRed += image[i + r][j + c].rgbtRed * gy[r + 1][c + 1];
                }
            }

            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            int sepiaRed = round(0.189 * (*pixel).rgbtBlue + 0.769 * (*pixel).rgbtGreen + 0.393 * (*pixel).rgbtRed);
            int sepiaGreen = round(0.168 * (*pixel).rgbtBlue + 0.686 * (*pixel).rgbtGreen + 0.349 * (*pixel).rgbtRed);
            int sepiaBlue = round(0.131 * (*pixel).rgbtBlue + 0.534 * (*pixel).rgbtGreen + 0.272 * (*pixel).rgbtRed);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            (*pixel).rgbtBlue = sepiaBlue;
            (*pixel).rgbtGreen = sepiaGreen;
            (*pixel).rgbtRed = sepiaRed;
        }
    }
    return;
}
