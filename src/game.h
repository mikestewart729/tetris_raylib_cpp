#ifndef GAME_H
#define GAME_H

#include "block.h"
#include "grid.h"

class Game 
{
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    Grid grid;

private:
    bool IsBlockOutside();
    std::vector<Block> blocks;
    Block current_block;
    Block next_block;
};

#endif