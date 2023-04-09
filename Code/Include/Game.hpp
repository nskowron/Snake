#pragma once

#include <Board.hpp>
#include <Snake.hpp>

class Game
{
private:
    Board _Board;
    Snake _Snake;

public:
    Game() : _Snake(&_Board), _Board(20)  { _Board.NewSnack(); }

    void Play();
};