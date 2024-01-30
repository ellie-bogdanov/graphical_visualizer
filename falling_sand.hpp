#pragma once

#include "graphical_visualizer.hpp"

#include <chrono>
#include <queue>
#include <string>
#include <vector>

using namespace std::chrono_literals;

const char SAND_SHAPE = '@';
const std::string SAND_DEFAULT_COLOR = "red";
const int SAND_BLOCK_AMOUNT = 20;
const int MIN_SAND_LENGTH = 5;
const int MAX_SAND_LENGTH = 50;
const std::chrono::milliseconds millis_per_frame_falling_sand = 20ms;

struct SandBlock { // represent a line of falling sand, each line consists of vector of pairs that represent the position of each sand particle within the block
    int length;
    int starting_position;
    char shape;
    std::string color;
    std::vector<std::pair<size_t, size_t>> links;

    SandBlock();
    SandBlock(std::string color);
};

class FallingSand { // consists of a frame that changes, the visualizer that prints the frames and a queue of sand blocks that after reaching a stop the next in queue falls
private:
    Frame field;
    GraphicalVisualizer visualizer;
    std::queue<SandBlock> sand_blocks;

public:
    FallingSand();
    void generate_sand_blocks();
    void simulate_fall();
    void simualte_diag_fall();

    Frame get_field() const;
};
