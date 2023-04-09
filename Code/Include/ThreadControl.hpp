#pragma once

#include <mutex>
#include <condition_variable>

extern std::mutex mtx;
extern std::condition_variable cv;