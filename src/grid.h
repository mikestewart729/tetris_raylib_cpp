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
    bool IsCellEmpty(int row, int col);
    int ClearFullRows();
    int grid[20][10];

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int num_rows);
    int num_rows;
    int num_cols;
    int cell_size;
    int vertical_offset;
    int horizontal_offset;
    std::vector<Color> colors;
};

#endif