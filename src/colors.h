#ifndef COLORS_H
#define COLORS_H

#include "../include/raylib.h"

#include <vector>

extern const Color dark_gray;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color light_blue;
extern const Color dark_blue;

std::vector<Color> GetCellColors();

#endif