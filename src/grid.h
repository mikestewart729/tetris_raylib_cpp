#ifndef GRID_H
#define GRID_H

#include <vector>
#include "../include/raylib.h"

class Grid 
{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int col);
    int grid[20][10];

private:
    int num_rows;
    int num_cols;
    int cell_size;
    int vertical_offset;
    std::vector<Color> colors;
};

#endif