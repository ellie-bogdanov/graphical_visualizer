#pragma once

#include "graphical_visualizer.hpp"

#include <chrono>
#include <queue>
#include <string>
#include <vector>

using namespace std::chrono_literals;

const char SAND_SHAPE = '@';
const std::string SAND_DEFAULT_COLOR = "red";
const int SAND_BLOCK_AMOUNT = 25;
const int MIN_SAND_LENGTH = 1;
const int MAX_SAND_LENGTH = 30;
const std::chrono::milliseconds millis_per_frame_falling_sand = 25ms;

struct SandBlock {
    int length;
    int starting_position;
    char shape;
    std::string color;
    std::vector<std::pair<size_t, size_t>> links;

    SandBlock();
    SandBlock(std::string color);
};

class FallingSand {
private:
    Frame field;
    GraphicalVisualizer visualizer;
    std::queue<SandBlock> sand_blocks;

public:
    FallingSand();
    void generate_sand_blocks();
    void simulate_fall();

    Frame get_field() const;
};
