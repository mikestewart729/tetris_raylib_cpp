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
    bool game_over;
    int score;

private:
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int lines_cleared, int move_down_points);
    std::vector<Block> blocks;
    Block current_block;
    Block next_block;
};

#endif