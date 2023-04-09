#pragma once

#include <Snake.hpp>
#include <BoardFieldStates.hpp>

#include <utility>

class Board
{
private:
    short Length;
    FieldState** Fields;
    //Snake* _Snake;
public:
    Board(short);
    ~Board();

    FieldState GetFieldState(std::pair<short, short>);
    void NewSnack();
    void SetOk(std::pair<unsigned short, unsigned short> field) { Fields[field.first][field.second] = OK; }
    void SetSnake(std::pair<unsigned short, unsigned short> field) { Fields[field.first][field.second] = SNAKE; }

    void Show();
};
