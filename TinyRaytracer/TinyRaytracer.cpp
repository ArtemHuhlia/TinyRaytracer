#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cmath>
#include <limits>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "geometry.h"

#define ENABLE_ALPHA 0

#if ENABLE_ALPHA
#error NEED TO IMPLEMENT
#define CHANEL_NUM 4
#else
#define CHANEL_NUM 3
#endif //ENABLE_ALPHA

uint8_t mapFloatTo255(float source)
{
    //clamp
    float clampedSource = std::max(0.f, std::min(1.f, source));
    return clampedSource * 255;
}

void render()
{
    const size_t height = 720;
    const size_t width = 1280;

    std::vector<Color> framebuffer(height * width);

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            uint8_t R = mapFloatTo255(float(i) / float(height));
            uint8_t G = mapFloatTo255(float(j) / float(width));
            framebuffer[i * width + j] = Color(R, G, 0.f);
        }
    }

    stbi_write_png("output.png", width, height, CHANEL_NUM, framebuffer.data(), CHANEL_NUM * sizeof(uint8_t) * width);
}

int main()
{
    render();
    return 0;
}