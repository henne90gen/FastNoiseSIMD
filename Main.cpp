#include <cstdlib>
#include <iostream>

#include "FastNoiseSIMD/FastNoiseSIMD.h"

int main() {
    auto noise = FastNoiseSIMD::NewFastNoiseSIMD();
    uint width = 100;
    uint height = 100;
    uint depth = 10;
    uint size = width * height * depth;
    auto *data = (float *) malloc(size * sizeof(float));
    for (unsigned int i = 0; i < size; i++) {
        data[i] = 0;
    }
    noise->FillSimplexSet(data, 0, 0, 0, width, height, depth);
    for (unsigned int z = 0; z < depth; z++) {
        for (unsigned int y = 0; y < height; y++) {
            for (unsigned int x = 0; x < width; x++) {
                std::cout << data[x + y * width + z * width * height] << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
