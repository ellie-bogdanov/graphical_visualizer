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

    if (y > 0 && grid[y - 1][x].character == game_of_life::CELL_SHAPE)
        ++amount_of_neighbors;
    if (y < Frame::FRAME_HEIGHT - 1 && grid[y + 1][x].character == game_of_life::CELL_SHAPE)
        ++amount_of_neighbors;

    if (grid[y][x].character == game_of_life::CELL_SHAPE && amount_of_neighbors < 2)
        return false;
    else if (grid[y][x].character == game_of_life::CELL_SHAPE && amount_of_neighbors > 3)
        return false;
    else if (grid[y][x].character == Frame::BACKGROUND && amount_of_neighbors != 3)
        return false;

    return true;
}

void simulate_game_of_life(Frame &frame, size_t amount_of_cycles, void (*game_conf)(frame_matrix &)) {
    GraphicalVisualizer visualizer;
    game_conf(frame.current_frame);
    visualizer.add_frame(frame);
    for (size_t cycle = 1; cycle <= amount_of_cycles; ++cycle) {
        std::set<std::pair<size_t, size_t>> alive_cells;
        for (size_t i = 0; i < Frame::FRAME_HEIGHT; ++i) {
            for (size_t j = 0; j < Frame::FRAME_WIDTH; ++j) {
                if (is_cell_alive(frame.current_frame, j, i))
                    alive_cells.insert({j, i});
            }
        }
        for (size_t i = 0; i < Frame::FRAME_WIDTH; ++i) {
            for (size_t j = 0; j < Frame::FRAME_HEIGHT; ++j) {
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

void glider_gun_conf(frame_matrix &grid) {
    size_t ref_point_y = Frame::FRAME_HEIGHT / 4;
    size_t ref_point_x = Frame::FRAME_WIDTH / 4;

    using namespace game_of_life;
    // left square
    grid[ref_point_y][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y][ref_point_x + 1] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x + 1] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    // left square

    // middle part 10 to right
    ref_point_x += 10;

    grid[ref_point_y][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 2][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y - 1][ref_point_x + 1] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 3][ref_point_x + 1] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y - 2][ref_point_x + 2] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 4][ref_point_x + 2] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y - 2][ref_point_x + 3] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 4][ref_point_x + 3] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x + 4] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y - 1][ref_point_x + 5] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 3][ref_point_x + 5] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y][ref_point_x + 6] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x + 6] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 2][ref_point_x + 6] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x + 7] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    // middle part

    // right part
    ref_point_x += 10;
    ref_point_y -= 2;

    grid[ref_point_y][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 2][ref_point_x] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y][ref_point_x + 1] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 1][ref_point_x + 1] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 2][ref_point_x + 1] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y - 1][ref_point_x + 2] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 3][ref_point_x + 2] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y - 1][ref_point_x + 4] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y - 2][ref_point_x + 4] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 3][ref_point_x + 4] = {CELL_SHAPE, colors.at(CELL_COLOR)};
    grid[ref_point_y + 4][ref_point_x + 4] = {CELL_SHAPE, colors.at(CELL_COLOR)};
}