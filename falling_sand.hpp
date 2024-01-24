#pragma once

#include "graphical_visualizer.hpp"

#include <chrono>
#include <queue>
#include <string>
#include <vector>

using namespace std::chrono_literals;

const char SAND_SHAPE = '@';
const std::string SAND_DEFAULT_COLOR = "red";
const int SAND_BLOCK_AMOUNT = 15;
const int MIN_SAND_LENGTH = 2;
const int MAX_SAND_LENGTH = 12;
const std::chrono::milliseconds millis_per_frame_falling_sand = 25ms;

struct sand_block {
    int length;
    int starting_position;
    char shape;
    std::string color;
    std::vector<std::pair<size_t, size_t>> links;

    sand_block();
    sand_block(std::string color);
};

class FallingSand {
  private:
    Frame field;
    GraphicalVisualizer visualizer;
    std::queue<sand_block> sand_blocks;

  public:
    FallingSand();
    void generate_sand_blocks();
    void simulate_fall();

    Frame get_field() const;
};
