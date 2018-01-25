/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Image.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Image_hpp
#define Image_hpp

#include "Linear/vec3.hpp"
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Image
 *
 *  Represents a ppm image with a depth and pixel
 *  component, along with methods for setting values
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Image
    {
    const unsigned width;
    const unsigned height;
    std::vector<Linear::vec3> pixelBuffer;
    std::vector<float> depthBuffer;
        
    /** 
     *  construct with a width, height and clear colour
     *
     *  OPTIMISATION: FILL BUFFER WITH FAR PLANES Z COORDINATE?
     */ 
    Image (unsigned _width, unsigned _height, Linear::vec3 fill):
        width (_width), height (_height),
        pixelBuffer (_width * _height),
        depthBuffer (_width * _height)
        {
        std::fill(depthBuffer.begin(), depthBuffer.end(), Linear::infinity);
        std::fill(pixelBuffer.begin(), pixelBuffer.end(), fill);
        }
    
    /** 
     *  map 0 - 1 rgb values to 0 - 255
     */ 
    int gamma (float r, float dc) const
        { return int(pow(std::min(1.0f, std::max(0.0f, r * dc)), 1.0f / 2.2f) * 255.0f); }
    
    /** 
     *  methods for mutating and checking the depth
     *  and colour buffers
     */ 
    void setPixel (int x, int y, Linear::vec3 radiance)
        { pixelBuffer [x + y * width] = radiance; }
    void addPixel (int x, int y, Linear::vec3 radiance)
        { pixelBuffer[x + y * width] += radiance; }
    Linear::vec3 getPixel (int x, int y) const
        { return pixelBuffer [x + y * width]; }
    void setDepth (int x, int y, float depth)
        { depthBuffer [x + y * width] = depth; }
    float getDepth (int x, int y) const
        { return depthBuffer [x + y * width]; }
        
    /** 
     *  write colour buffer to a ppm file
     */ 
    void writePixels (std::string path, float dc = 15.0f) const
        {
        FILE* file = fopen((path + ".ppm").c_str(), "wt+");
        fprintf(file, "P3 %d %d 255\n", width, height);
        float yth = height * 0.02;
        float xth = height * 0.02;
        for (int y = 0; y < height; ++y)
            {
            fprintf(file, "\n# y = %d\n", y);
            for (int x = 0; x < width; ++x)
                {
                if (fabs(height - y) < yth || fabs(width - x) < xth || y < yth || x < xth)
                    { // add boarder
                    fprintf(file, "64 64 64\n");
                    } // add boarder
                else
                    { // write pixels to file
                    Linear::vec3 rad = getPixel(x, y);
                    fprintf(file, "%d %d %d\n", gamma(rad.r, dc), gamma(rad.g, dc), gamma(rad.b, dc));
                    } // write pixels to file
                }
            }
        fclose(file);
        }
    
    /** 
     *  write depth buffer to a ppm file (debug)
     */ 
    void writeDepth (std::string path, float dc = 15.0f) const
        {
        float far = 100;
        float near = 0.01;

        FILE* file = fopen(("ppm/depth_" + path + ".ppm").c_str(), "wt+");
        fprintf(file, "P3 %d %d 255\n", width, height);
        for (int y = 0; y < height; ++y)
            {
            fprintf(file, "\n# y = %d\n", y);
            for (int x = 0; x < width; ++x)
                {
                std::cout << getDepth(x, y) << std::endl;
                    
                float rad = (2.0 * near) / (far + near - getDepth(x, y) * (far - near));
                Linear::vec3 colour (getDepth(x, y) * 0.0125);
                fprintf(file, "%d %d %d\n", gamma(colour.r, dc), gamma(colour.g, dc), gamma(colour.b, dc));
                }
            }
        fclose(file);
        }
    };


#endif /* Image_h */
