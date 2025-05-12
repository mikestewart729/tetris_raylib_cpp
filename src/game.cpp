#include "game.h"

#include "blocks.h"

#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
    game_over = false;
    score = 0;
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
    next_block.Draw(125, 125);
}

void Game::HandleInput()
{
    int key_pressed { GetKeyPressed() };
    if (game_over && key_pressed != 0)
    {
        game_over = false;
        Reset();
    }
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
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (!game_over)
    {
        current_block.Move(0, -1);
        if (IsBlockOutside() || !BlockFits())
        {
            current_block.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if (!game_over)
    {
        current_block.Move(0, 1);
        if (IsBlockOutside() || !BlockFits()) 
        {
            current_block.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!game_over)
    {
        current_block.Move(1, 0);
        if (IsBlockOutside() || !BlockFits())
        {
            current_block.Move(-1, 0);
            LockBlock();
        }
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
    if (!game_over)
    {
        current_block.Rotate();
        if (IsBlockOutside())
        {
            current_block.UndoRotation();
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles { current_block.GetCellPositions() };
    for (Position tile : tiles)
    {
        grid.grid[tile.row][tile.col] = current_block.id;
    }
    current_block = next_block;
    if (!BlockFits())
    {
        game_over = true;
    }
    next_block = GetRandomBlock();
    int rows_cleared = grid.ClearFullRows();
    UpdateScore(rows_cleared, 0);
}

bool Game::BlockFits()
{
    std::vector<Position> tiles { current_block.GetCellPositions() };
    for (Position tile : tiles)
    {
        if (!grid.IsCellEmpty(tile.row, tile.col))
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int lines_cleared, int move_down_points)
{
    switch (lines_cleared)
    {
    case 1: 
        score += 100;
        break;
    case 2: 
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += move_down_points;
}