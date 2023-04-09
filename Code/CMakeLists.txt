file (GLOB SOURCE Src/Game.cpp Src/*.cpp UI/*.cpp main.cpp)
include_directories(Include)

add_executable(Snake ${SOURCE})

target_link_options(Snake PRIVATE -static)