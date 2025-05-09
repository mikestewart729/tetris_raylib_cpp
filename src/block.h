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
    void Draw();
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
};

#endif