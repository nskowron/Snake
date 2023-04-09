#include <Board.hpp>

#include <random>

#include <iostream>

Board::Board(short length)
{
    std::cout << "board\n";
    if(length >= 10 && length <= 100)
    {
        Length = length;
        Fields = new FieldState*[length];
        for(unsigned short x = 0; x < length; ++x)
        {
            Fields[x] = new FieldState[length];
            for(unsigned short y = 0; y < length; ++y)
            {
                Fields[x][y] = OK;
            }
        }
        return;
    }
    throw("Wrong board size!\n");
}

Board::~Board()
{
    for(unsigned short x = 0; x < Length; ++x)
    {
        delete [] Fields[x];
    }
}

FieldState Board::GetFieldState(std::pair<short, short> field)
{
    if(field.first < 0 || field.second < 0 || field.first >= Length || field.second >= Length)
        return EDGE;

    return Fields[field.first][field.second];
}

void Board::NewSnack()
{
    unsigned short x, y;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, Length - 1);

    do
    {
        x = dist(gen);
        y = dist(gen);
    } while (Fields[x][y] != OK);
    
    Fields[x][y] = SNACK;
}
