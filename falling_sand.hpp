#pragma once

#include "graphical_visualizer.hpp"

#include <chrono>
#include <queue>
#include <string>
#include <vector>

using namespace std::chrono_literals;

namespace fallind_sand {
    const char SAND_SHAPE = '*';
    const std::string SAND_DEFAULT_COLOR = "yellow";
    const int SAND_BLOCK_AMOUNT = 15;
    const int MIN_SAND_LENGTH = 10;
    const int MAX_SAND_LENGTH = 55;
    const std::chrono::milliseconds MILLIS_PER_FRAME = 20ms;

    int generate_random_length();
    int generate_random_start_pos(int sand_length);
    int generate_random_direction();
}

struct sand_block { // represent a line of falling sand, each line consists of vector of pairs that represent the position of each sand particle within the block
    int length;
    int starting_position;
    char shape;
    std::string color;
    std::vector<std::pair<size_t, size_t>> links;

    sand_block();
    sand_block(std::string color);
};

class falling_sand { // consists of a frame that changes, the visualizer that prints the frames and a queue of sand blocks that after reaching a stop the next in queue falls
private:
    frame field;
    GraphicalVisualizer visualizer;
    std::queue<sand_block> sand_blocks;

public:
    falling_sand();
    void generate_sand_blocks();
    void simulate_fall();
    void simualte_diag_fall();

    frame get_field() const;
};
