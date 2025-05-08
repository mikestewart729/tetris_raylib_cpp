#include "grid.h"
#include <iostream>

Grid::Grid()
{
    num_rows = 20;
    num_cols = 10;
    cell_size = 30;
    Initialize();
}

void Grid::Initialize()
{
    for (int row { 0 }; row < num_rows; ++row)
    {
        for (int col { 0 }; col < num_cols; ++col)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print()
{
    for (int row { 0 }; row < num_rows; ++row)
    {
        for (int col { 0 }; col < num_cols; ++col)
        {
            std::cout << grid[row][col] << ' ';
        }
        std::cout << '\n';
    }
}