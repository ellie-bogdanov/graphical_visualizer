#pragma once

#include "graphical_visualizer.hpp"

#include <string>
#include <vector>
#include <queue>
#include <chrono>

using namespace std::chrono_literals;

const char SAND_SHAPE = '@';
const std::string SAND_DEFAULT_COLOR = "red";
const int SAND_BLOCK_AMOUNT = 10;
const int MIN_SAND_LENGTH = 10;
const int MAX_SAND_LENGTH = 20;
const std::chrono::milliseconds millis_per_frame_falling_sand = 50ms;

struct sand_block
{
    int length;
    int starting_position;
    char shape;
    std::string color;
    std::vector<std::pair<size_t, size_t>>links;

    sand_block();
    sand_block(std::string color);

};


class falling_sand
{
private:
    frame field;
    graphical_visualizer visualizer;  
    std::queue<sand_block> sand_blocks;
    



public:
    falling_sand();
    void generate_sand_blocks();
    void simulate_fall();

    frame get_field() const;
    
};
