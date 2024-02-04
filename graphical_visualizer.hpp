#pragma once

#include <chrono>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, char const *> colors = {{"red", "\033[31m"}, {"green", "\033[32m"}, {"blue", "\033[34m"}, {"yellow", "\033[33m"}, {"reset", "\033[0m"}};

void gotoxy(size_t x, size_t y);

struct Pixel { // represents every single character on terminal
    char character;
    char const *color_code;

    bool operator==(Pixel const &compare);
    bool operator!=(Pixel const &compare);
};

using frame_matrix = std::vector<std::vector<Pixel>>;

class Frame { // consists of a pixel matrix, methods to manipulate and print the frame and consts for more flexebility
private:
    void initialize_frame();

    bool is_valid_input(std::string const &height_start, std::string const &height_length, std::string const &range_start, std::string const &range_length, std::string const &printable_char, std::string const &color);

public:
    frame_matrix current_frame;
    const static size_t AMOUNT_OF_INPUT_OPTIONS = 6;
    const static size_t FRAME_WIDTH = 60;
    const static size_t FRAME_HEIGHT = 20;
    const static char INPUT_DELIMITER = ',';
    const static char BACKGROUND = ' ';

    Frame();
    Frame(std::string const &input);

    frame_matrix get_current_frame() const;
    void alter_frame(std::string const &input);
    void set_current_frame(frame_matrix const &new_current_frame);
    void print_frame();
    void print_frame(Frame const &prev_frame);
    bool parse_input(std::string const &input);
};

class GraphicalVisualizer { // consists of a queue of frames and methods that manipulate the queue and prints the frames in order
private:
    std::queue<Frame> frame_queue;

public:
    GraphicalVisualizer();

    std::queue<Frame> get_frame_queue() const;
    void add_frame(Frame frame);
    void print_sequence(const std::chrono::milliseconds millis);
    void print_sequence_no_clear(const std::chrono::milliseconds millis);
};