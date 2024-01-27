#include "graphical_visualizer.hpp"

#include <iostream>
#include <sstream>
#include <thread>

void gotoxy(size_t x, size_t y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

bool Pixel::operator==(Pixel const &compare) {
    return character == compare.character && *color_code == *compare.color_code;
}

bool Pixel::operator!=(Pixel const &compare) {
    return character != compare.character || *color_code != *compare.color_code;
}

Frame::Frame() { initialize_frame(); }

Frame::Frame(const std::string &input) {
    initialize_frame();
    alter_frame(input);
}

frame_matrix Frame::get_current_frame() const { return current_frame; }

void Frame::alter_frame(std::string const &input) {
    if (!parse_input(input))
        std::cout << "Invalid input \n";
}

void Frame::set_current_frame(frame_matrix const &new_current_frame) {
    current_frame = new_current_frame;
}

void Frame::print_frame() {
    for (auto const &line : current_frame) {
        for (auto const &current_pixel : line) {
            std::cout << current_pixel.color_code << current_pixel.character;
            std::cout << colors.at("reset");
        }

        std::cout << std::endl;
    }
}

void Frame::print_frame(Frame const &prev_frame) {
    for (size_t i = 0; i < FRAME_HEIGHT; ++i) {
        for (size_t j = 0; j < FRAME_WIDTH; ++j) {
            if (current_frame[i][j] != prev_frame.current_frame[i][j]) {
                gotoxy(j, i);
                std::cout << current_frame[i][j].color_code << current_frame[i][j].character;
                std::cout << colors.at("reset");
            }
        }
    }
}

bool Frame::parse_input(std::string const &input) {
    std::stringstream input_stream(input);

    std::string input_sections[AMOUNT_OF_INPUT_OPTIONS];

    size_t input_sections_index = 0;
    while (std::getline(input_stream, input_sections[input_sections_index],
                        INPUT_DELIMITER))
        ++input_sections_index;

    if (!is_valid_input(input_sections[0], input_sections[1], input_sections[2],
                        input_sections[3], input_sections[4],
                        input_sections[5])) {
        return false;
    }

    int height_start = std::stoi(input_sections[0]);

    int height_length = std::stoi(input_sections[1]);

    int range_start = std::stoi(input_sections[2]);

    int range_length = std::stoi(input_sections[3]);

    char const *color = colors.at(input_sections[5]);

    char printable_char = input_sections[4][0]; // should always be a string of length 1

    for (size_t i = height_start; i <= height_start + height_length - 1; ++i) {
        for (size_t j = range_start; j <= range_start + range_length - 1; ++j) {
            current_frame[i][j].character = printable_char;
            current_frame[i][j].color_code = color;
        }
    }

    return true;
}

void Frame::initialize_frame() {
    for (size_t i = 0; i < FRAME_HEIGHT; ++i) {
        std::vector<Pixel> line;
        line.reserve(FRAME_WIDTH);
        for (size_t j = 0; j < FRAME_WIDTH; ++j)
            line.push_back({BACKGROUND, colors.at("reset")});

        current_frame.push_back(line);
    }
}

bool is_a_number(std::string const &number) {
    for (char const &ch : number) {
        if (!std::isdigit(ch))
            return false;
    }

    return true;
}

bool Frame::is_valid_input(std::string const &height_start, std::string const &height_length, std::string const &range_start, std::string const &range_length, std::string const &printable_char, std::string const &color) {

    auto pos = colors.find(color);

    if (pos == colors.end())
        return false;

    if (!is_a_number(height_start) || !is_a_number(height_start) ||
        !is_a_number(height_start) || !is_a_number(height_start)) {
        return false;
    }
    if (printable_char.size() != 1)
        return false;

    int height_start_int = std::stoi(height_start);
    int height_length_int = std::stoi(height_length);
    int range_start_int = std::stoi(range_start);
    int range_length_int = std::stoi(range_length);

    if (height_start_int < 0 ||
        height_length_int + height_length_int - 1 >= FRAME_HEIGHT ||
        range_start_int < 0 ||
        range_start_int + range_length_int - 1 >= FRAME_WIDTH)
        return false;
    return true;
}

GraphicalVisualizer::GraphicalVisualizer() { frame_queue = {}; }

std::queue<Frame> GraphicalVisualizer::get_frame_queue() const {
    return frame_queue;
}

void GraphicalVisualizer::add_frame(Frame frame) { frame_queue.push(frame); }

void GraphicalVisualizer::print_sequence(const std::chrono::milliseconds millis) {
    std::queue<Frame> local_temp_queue = frame_queue;

    while (local_temp_queue.size() > 1) {

        local_temp_queue.front().print_frame();
        local_temp_queue.pop();

        std::this_thread::sleep_for(millis);
        system("clear");
    }

    local_temp_queue.front().print_frame();
    local_temp_queue.pop();
}

void GraphicalVisualizer::print_sequence_no_clear(const std::chrono::milliseconds millis) {
    std::queue<Frame> local_temp_queue = frame_queue;
    local_temp_queue.front().print_frame();
    while (local_temp_queue.size() > 1) {
        Frame last_frame = local_temp_queue.front();
        local_temp_queue.pop();
        local_temp_queue.front().print_frame(last_frame);

        std::this_thread::sleep_for(millis);
        // system("clear");
    }

    local_temp_queue.front().print_frame();
    local_temp_queue.pop();
    system("clear");
}