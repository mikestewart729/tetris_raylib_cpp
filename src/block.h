#ifndef BLOCK_H
#define BLOCK_H

#include "colors.h"
#include "position.h"

#include <map>
#include <vector>

class Block 
{
public:
    Block();
    void Draw(int offset_x = 1, int offset_y = 1);
    void Move(int rows, int cols);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cell_size;
    int rotation_state;
    std::vector<Color> colors;
    int row_offset;
    int col_offset;
    // Needed due to weird way screen is rendering on my computer
    int vertical_offset;
    int horizontal_offset;
};

#endif