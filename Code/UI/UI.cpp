#include <Game.hpp>

#include <iostream>
#include <Windows.h>

void Board::Show()
{
    system("cls");

    std::cout << "/ ";
    for(unsigned short x = 0; x < Length; ++x)
        std::cout << "- ";
    std::cout << "\\" << std::endl;

    for(short y = Length - 1; y >= 0; --y)
    {
        std::cout << "| ";
        for(short x = 0; x < Length; ++x)
        {
            switch(Fields[x][y])
            {
                case OK:    std::cout << "  "; break;
                case SNAKE: std::cout << "# "; break;
                case SNACK: std::cout << "$ "; break;
            }
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "\\ ";
    for(unsigned short x = 0; x < Length; ++x)
        std::cout << "- ";
    std::cout << "/" << std::endl;
}
