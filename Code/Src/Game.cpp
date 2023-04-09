#include <ThreadControl.hpp>
#include <Game.hpp>

#include <chrono>
#include <thread>
#include <Windows.h>
#include <atomic>

#include <iostream>

void Game::Play()
{
    std::atomic<bool> end_game{false};
    std::atomic<bool> moved;

    while(!end_game)
    {
        _Board.Show();

        moved.store(false);

        std::thread movement(&Snake::Move, &_Snake, std::ref(end_game), std::ref(moved));
        while(!moved)
        {
            if(GetAsyncKeyState('W') & 0x8000)
            {
                _Snake.SetDirection(UP);
                break;
            }
            else if(GetAsyncKeyState('S') & 0x8000)
            {
                _Snake.SetDirection(DOWN);
                break;
            }
            else if(GetAsyncKeyState('A') & 0x8000)
            {
                _Snake.SetDirection(LEFT);
                break;
            }
            else if(GetAsyncKeyState('D') & 0x8000)
            {
                _Snake.SetDirection(RIGHT);
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        if(movement.joinable())
            movement.join();
    }
}