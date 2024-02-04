#pragma once

#include "graphical_visualizer.hpp"
#include <string>

using namespace std::chrono_literals;

namespace game_of_life {
    char const CELL_SHAPE = '*';
    std::string const CELL_COLOR = "green";
    const std::chrono::milliseconds MILLIS_PER_FRAME = 100ms;

    bool is_cell_alive(frame_matrix const &grid, size_t x, size_t y);

    void simulate_game_of_life(Frame &frame, size_t amount_of_cycles, void (*game_conf)(frame_matrix &));

    void glider_gun_conf(frame_matrix &grid);
}
