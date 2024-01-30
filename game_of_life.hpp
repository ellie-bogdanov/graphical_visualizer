#pragma once

#include "graphical_visualizer.hpp"
#include <string>

using namespace std::chrono_literals;

namespace game_of_life {
    char const CELL_SHAPE = '*';
    std::string const CELL_COLOR = "blue";
    const std::chrono::milliseconds millis_per_frame_game_of_life = 250ms;
}

bool is_cell_alive(frame_matrix const &grid, size_t x, size_t y);

void simulate_game_of_life(Frame &frame, size_t amount_of_cycles);