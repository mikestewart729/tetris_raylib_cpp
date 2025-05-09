#include "block.h"

Block::Block()
{
    cell_size = 15;
    rotation_state = 0;
    colors = GetCellColors();
    // Needed for the same reason as given in grid.cpp. Very unclear why.
    vertical_offset = 300;
}

void Block::Draw()
{
    std::vector<Position> tiles { cells[rotation_state] };
    for (Position tile : tiles)
    {
        DrawRectangle(
            tile.col * cell_size + 1,
            tile.row * cell_size + 1 + vertical_offset,
            cell_size - 1,
            cell_size - 1,
            colors[id]
        );
    }
}