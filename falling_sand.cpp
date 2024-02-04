#include "falling_sand.hpp"

#include <random>

int generate_random_length() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(MIN_SAND_LENGTH, MAX_SAND_LENGTH); // distribution in range [MIN_SAND_LENGTH, MAX_SAND_LENGTH]

    return dist(rng);
}

int generate_random_start_pos(int sand_length) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, Frame::FRAME_WIDTH - sand_length);

    return dist(rng);
}

SandBlock::SandBlock() { // generate random starting possition and length of the block and the pushes the particles into the vector of links
    length = generate_random_length();
    starting_position = generate_random_start_pos(length);
    shape = SAND_SHAPE;
    color = SAND_DEFAULT_COLOR;
    for (size_t i = starting_position; i <= starting_position + length - 1; ++i) {
        links.push_back({0, i});
    }
}

SandBlock::SandBlock(std::string color) : color(color) { // same as without params but sets the color to the provided one instead of default const
    length = generate_random_length();
    starting_position = generate_random_start_pos(length);
    shape = SAND_SHAPE;
    for (size_t i = starting_position; i <= starting_position + length - 1; ++i) {
        links.push_back({0, i});
    }
}

FallingSand::FallingSand() {
    generate_sand_blocks();
    // simulate_fall();
    simualte_diag_fall();
    system("clear");
    visualizer.print_sequence(millis_per_frame_falling_sand);
}

void FallingSand::generate_sand_blocks() {
    for (size_t i = 1; i <= SAND_BLOCK_AMOUNT; ++i) {

        sand_blocks.push(SandBlock());
    }
}

void FallingSand::simulate_fall() { // the simulation itself this is version without daig falls of sand particles only in the y axis

    while (!sand_blocks.empty()) {
        SandBlock current_block = sand_blocks.front();

        bool did_move = true;
        while (did_move) {
            did_move = false;
            visualizer.add_frame(field); // adds the current state of frame to the visualizer queue

            frame_matrix new_frame = field.get_current_frame();

            for (size_t i = 0; i < current_block.links.size(); ++i) {
                std::pair<size_t, size_t> link = current_block.links[i]; // tracks the current sand particle

                // checks for bounds
                if (link.first != Frame::FRAME_HEIGHT - 1 && field.get_current_frame()[link.first + 1][link.second].character != current_block.shape) {
                    did_move = true;
                    // resets the color and shape of current place, then updates the color and shape of the one below
                    new_frame[current_block.links[i].first][current_block.links[i].second] = {Frame::BACKGROUND, colors.at("reset")};
                    current_block.links[i].first += 1;
                    new_frame[current_block.links[i].first][current_block.links[i].second] = {current_block.shape, colors.at(current_block.color)};
                }
            }

            field.set_current_frame(new_frame);
        }
        sand_blocks.pop();
    }
}

int generate_random_direction() { // generates random direction for diag fall either fall left or right
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

    return dist(rng);
}

void FallingSand::simualte_diag_fall() {
    while (!sand_blocks.empty()) {
        SandBlock current_block = sand_blocks.front();

        bool did_move = true;
        while (did_move) {
            did_move = false;
            visualizer.add_frame(field);
            frame_matrix new_frame = field.get_current_frame();

            for (size_t i = 0; i < current_block.links.size(); ++i) {
                std::pair<size_t, size_t> link = current_block.links[i];

                if (link.first != Frame::FRAME_HEIGHT - 1) {
                    bool move_down = false;
                    bool move_diag_left = false;
                    bool move_diag_right = false;

                    if (field.get_current_frame()[link.first + 1][link.second].character != current_block.shape) {
                        move_down = true;
                    } else {
                        if (link.second != Frame::FRAME_WIDTH - 1 && field.get_current_frame()[link.first + 1][link.second + 1].character != current_block.shape) {
                            move_diag_right = true;
                            move_down = true;
                        }
                        if (link.second != 0 && field.get_current_frame()[link.first + 1][link.second - 1].character != current_block.shape) {
                            move_diag_left = true;
                            move_down = true;
                        }
                    }

                    int direction = (generate_random_direction() == 0 && move_diag_left) ? -1 : (move_diag_right) ? 1
                                                                                                                  : 0;

                    new_frame[current_block.links[i].first][current_block.links[i].second] = {Frame::BACKGROUND, colors.at("reset")};
                    current_block.links[i].first += (move_down ? 1 : 0);
                    current_block.links[i].second += direction;
                    new_frame[current_block.links[i].first][current_block.links[i].second] = {current_block.shape, colors.at(current_block.color)};
                    if (move_down)
                        did_move = true;
                }
            }

            field.set_current_frame(new_frame);
        }
        sand_blocks.pop();
    }
}

Frame FallingSand::get_field() const {
    return field;
}
