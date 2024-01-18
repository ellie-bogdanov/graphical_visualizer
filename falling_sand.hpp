#pragma once

#include "graphical_visualizer.hpp"

#include <string>
#include <vector>
#include <queue>

const char SAND_SHAPE = '@';
const std::string SAND_DEFAULT_COLOR = "yellow";
const int SAND_BLOCK_AMOUNT = 5;
const int MIN_SAND_LENGTH = 1;
const int MAX_SAND_LENGTH = 5;

struct sand_block
{
    int length;
    int starting_position;
    char shape;
    std::string color;

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
};