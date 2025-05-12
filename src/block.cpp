#include "block.h"

Block::Block()
{
    cell_size = 15;
    rotation_state = 0;
    colors = GetCellColors();
    row_offset = 0;
    col_offset = 0;
    // Needed for the same reason as given in grid.cpp. Very unclear why.
    vertical_offset = 315;
    horizontal_offset = 5;
}

void Block::Draw(int offset_x, int offset_y)
{
    std::vector<Position> tiles { GetCellPositions() };
    for (Position tile : tiles)
    {
        DrawRectangle(
            tile.col * cell_size + horizontal_offset + offset_x,
            tile.row * cell_size + vertical_offset + offset_y,
            cell_size - 1,
            cell_size - 1,
            colors[id]
        );
    }
}

void Block::Move(int rows, int cols)
{
    row_offset += rows;
    col_offset += cols;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles { cells[rotation_state] };
    std::vector<Position> moved_tiles;
    for (Position tile : tiles) 
    {
        Position new_position { 
            Position(
                tile.row + row_offset, tile.col + col_offset
            ) 
        };
        moved_tiles.push_back(new_position);
    }
    
    return moved_tiles;
}

void Block::Rotate()
{
    rotation_state++;
    if (rotation_state == static_cast<int>(cells.size()))
    {
        rotation_state = 0;
    }
}

void Block::UndoRotation()
{
    rotation_state--;
    if (rotation_state < 0)
    {
        rotation_state = cells.size() - 1;
    }
}