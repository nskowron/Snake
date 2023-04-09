#include <ThreadControl.hpp>
#include <Snake.hpp>

#include <chrono>
#include <thread>

#include <iostream>

std::mutex mtx;
std::condition_variable cv;

Snake::Snake(Board* board) : _Board(board), Direction{RIGHT}, Body({{4,3},{3,3},{2,3},{1,3}})
{
    std::cout << "snake\n";
    for(auto field : Body)
    {
        board->SetSnake(field);
    }
}

void Snake::SetDirection(SnakeDirection direction)
{
    switch(direction)
    {
        case UP:    if(Direction == DOWN) return; break;
        case DOWN:  if(Direction == UP) return; break;
        case LEFT:  if(Direction == RIGHT) return; break;
        case RIGHT: if(Direction == LEFT) return; break;
    }
    Direction.store(direction);
}

void Snake::Move(std::atomic<bool>& end, std::atomic<bool>& moved)
{
    //std::unique_lock<std::mutex> lock(mtx);

    std::pair<short, short> target = Body[0];
    switch(Direction)
    {
        case UP:    ++target.second; break;
        case DOWN:  --target.second; break;
        case LEFT:  --target.first; break;
        case RIGHT: ++target.first; break;
    }
    switch(_Board->GetFieldState(target))
    {
        case EDGE:  end.store(true); moved.store(true); return;
        case SNAKE: end.store(true); moved.store(true); return;
        case SNACK: _Board->NewSnack(); break;
        case OK:    _Board->SetOk(Body[Body.size() - 1]);
                    Body.pop_back();
    }
    _Board->SetSnake(target);
    Body.insert(Body.begin(), target);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    moved.store(true);
    //lock.unlock();
    //cv.notify_one();
}
