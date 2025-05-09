#include "grid.h"
#include <iostream>

Grid::Grid()
{
    num_rows = 20;
    num_cols = 10;
    cell_size = 15;
    // needed to make the grid and boxes appear within the window on my machine
    // It is unclear why (0, 0) is not the upper left corner of the window
    vertical_offset = 300; 
    Initialize();
    colors = GetCellColors();
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

std::vector<Color> Grid::GetCellColors()
{
    Color dark_grey = { 26, 31, 40, 255 };
    Color green = { 47, 230, 23, 255 };
    Color red = { 232, 18, 18, 255 };
    Color orange = { 226, 116, 17, 255 };
    Color yellow = { 237, 234, 4, 255 };
    Color purple = { 166, 0 , 247, 255 };
    Color cyan = { 21, 204, 209, 255 };
    Color blue = { 13, 64, 216, 255 };

    return { dark_grey, green, red, orange, yellow, purple, cyan, blue };
}

void Grid::Draw() 
{
    for (int row { 0 }; row < num_rows; ++row)
    {
        for (int col { 0 }; col < num_cols; ++col)
        {
            int cell_value = grid[row][col];
            DrawRectangle(
                col * cell_size + 1, 
                row * cell_size + 1 + vertical_offset, 
                cell_size - 1, 
                cell_size - 1, 
                colors[cell_value]
            );
        }
    }
}