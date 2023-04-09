#pragma once

#include <Board.hpp>
#include <BoardFieldStates.hpp>
#include <SnakeDirections.hpp>

#include <vector>
#include <utility>
#include <atomic>

class Board;
class Snake
{
private:
    std::vector< std::pair<unsigned short, unsigned short> > Body;
    std::atomic<SnakeDirection> Direction;
    Board* _Board;

public:
    Snake(Board*);
    void Move(std::atomic<bool>&, std::atomic<bool>&);
    void SetDirection(SnakeDirection);
};
