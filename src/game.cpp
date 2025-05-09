#include "game.h"

#include "blocks.h"

#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int random_index { static_cast<int>(rand() % blocks.size()) };
    Block block { blocks[random_index] };
    blocks.erase(blocks.begin() + random_index);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw()
{
    grid.Draw();
    current_block.Draw();
}

void Game::HandleInput()
{
    int key_pressed { GetKeyPressed() };
    switch (key_pressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    current_block.Move(0, -1);
    if (IsBlockOutside())
    {
        current_block.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    current_block.Move(0, 1);
    if (IsBlockOutside())
    {
        current_block.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    current_block.Move(1, 0);
    if (IsBlockOutside())
    {
        current_block.Move(-1, 0);
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles { current_block.GetCellPositions() };
    for (Position tile : tiles)
    {
        if (grid.IsCellOutside(tile.row, tile.col))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    current_block.Rotate();
    if (IsBlockOutside())
    {
        current_block.UndoRotation();
    }
}