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
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cell_size;
    int rotation_state;
    std::vector<Color> colors;
    int vertical_offset;
};

#endif