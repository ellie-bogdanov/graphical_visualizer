#include "graphical_visualizer.hpp"

#include <iostream>
#include <sstream>
#include <thread>

Pixel &Pixel::operator=(Pixel const &new_pixel) {
    character = new_pixel.character;
    color_code = new_pixel.color_code;

    return *this;
}

FrameMatrix::FrameMatrix() {
    height = Frame::FRAME_HEIGHT;
    width = Frame::FRAME_WIDTH;
    // frame_matrix.reserve(height * width);
}

Pixel &FrameMatrix::at(size_t height_index, size_t width_index) {
    return frame_matrix[height_index + Frame::FRAME_WIDTH * width_index];
}

void FrameMatrix::set(size_t height_index, size_t width_index, Pixel const &new_pixel) {
    frame_matrix[height_index + Frame::FRAME_WIDTH * width_index] = new_pixel;
}

void FrameMatrix::push_back_line(std::vector<Pixel> const &line) {
    if (frame_matrix.size() + line.size() > height * width)
        throw(505);
    else {
        for (Pixel const &pixel : line)
            frame_matrix.push_back(pixel);
    }
}

size_t FrameMatrix::size() {
    return height * width;
}

Frame::Frame() { initialize_frame(); }

Frame::Frame(const std::string &input) {
    initialize_frame();
    alter_frame(input);
}

FrameMatrix Frame::get_current_frame() const { return frame_matrix; }

void Frame::alter_frame(std::string const &input) {
    if (!parse_input(input))
        std::cout << "Invalid input \n";
}

void Frame::set_current_frame(FrameMatrix const &new_current_frame) {
    frame_matrix = new_current_frame;
}

void Frame::print_frame() {

    for (size_t i = 0; i < frame_matrix.height; ++i) {
        for (size_t j = 0; j < frame_matrix.width; ++j) {
            std::cout << frame_matrix.at(i, j).color_code << frame_matrix.at(i, j).character;
            std::cout << colors.at("reset");
        }
        std::cout << '\n';
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

    char printable_char =
        input_sections[4][0]; // should always be a string of length 1

    for (size_t i = height_start; i <= height_start + height_length - 1; ++i) {
        for (size_t j = range_start; j <= range_start + range_length - 1; ++j) {
            frame_matrix.at(i, j).character = printable_char;
            frame_matrix.at(i, j).color_code = color;
        }
    }

    return true;
}

void Frame::initialize_frame() {
    for (size_t i = 0; i < FRAME_HEIGHT; ++i) {
        std::vector<Pixel> line;
        // line.reserve(FRAME_WIDTH);
        for (size_t j = 0; j < FRAME_WIDTH; ++j)
            line.push_back({BACKGROUND, colors.at("reset")});

        frame_matrix.push_back_line(line);
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

void GraphicalVisualizer::print_sequence(
    const std::chrono::milliseconds millis) {
    std::queue<Frame> local_temp_queue = frame_queue;

    while (!local_temp_queue.empty()) {
        local_temp_queue.front().print_frame();
        local_temp_queue.pop();
        std::this_thread::sleep_for(millis);
        system("clear");
    }
}