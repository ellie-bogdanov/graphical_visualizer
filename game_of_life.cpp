#include "game_of_life.hpp"

#include <set>

bool is_cell_alive(frame_matrix const &grid, size_t x, size_t y) {
    int amount_of_neighbors = 0;
    if (x > 0) {
        if (grid[y][x - 1].character == game_of_life::CELL_SHAPE)
            ++amount_of_neighbors;
        if (y > 0 && grid[y - 1][x - 1].character == game_of_life::CELL_SHAPE)
            ++amount_of_neighbors;
        if (y < Frame::FRAME_HEIGHT - 1 && grid[y + 1][x - 1].character == game_of_life::CELL_SHAPE)
            ++amount_of_neighbors;
    }
    if (x < Frame::FRAME_WIDTH - 1) {
        if (grid[y][x + 1].character == game_of_life::CELL_SHAPE)
            ++amount_of_neighbors;
        if (y > 0 && grid[y - 1][x + 1].character == game_of_life::CELL_SHAPE)
            ++amount_of_neighbors;
        if (y < Frame::FRAME_HEIGHT - 1 && grid[y + 1][x + 1].character == game_of_life::CELL_SHAPE)
            ++amount_of_neighbors;
    }

    if (grid[y][x].character == game_of_life::CELL_SHAPE && amount_of_neighbors < 2)
        return false;
    else if (grid[y][x].character == game_of_life::CELL_SHAPE && amount_of_neighbors > 3)
        return false;
    else if (grid[y][x].character == Frame::BACKGROUND && amount_of_neighbors != 3)
        return false;

    return true;
}

void simulate_game_of_life(Frame &frame, size_t amount_of_cycles) {
    GraphicalVisualizer visualizer;
    visualizer.add_frame(frame);
    for (size_t cycle = 1; cycle <= amount_of_cycles; ++cycle) {
        std::set<std::pair<size_t, size_t>> alive_cells;
        for (size_t i = 0; i < Frame::FRAME_HEIGHT; ++i) {
            for (size_t j = 0; j < Frame::FRAME_WIDTH; ++j) {
                if (is_cell_alive(frame.current_frame, j, i))
                    alive_cells.insert({i, j});
            }
        }
        for (size_t i = 0; i < Frame::FRAME_HEIGHT; ++i) {
            for (size_t j = 0; j < Frame::FRAME_WIDTH; ++j) {
                auto find_cell = alive_cells.find({i, j});
                if (find_cell != alive_cells.cend())
                    frame.current_frame[j][i] = {game_of_life::CELL_SHAPE, colors.at(game_of_life::CELL_COLOR)};
                else
                    frame.current_frame[j][i] = {Frame::BACKGROUND, colors.at("reset")};
            }
        }
        visualizer.add_frame(frame);
    }
    visualizer.print_sequence(game_of_life::millis_per_frame_game_of_life);
}