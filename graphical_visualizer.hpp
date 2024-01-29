#pragma once

#include <chrono>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, char const *> colors = {{"red", "\033[31m"}, {"green", "\033[32m"}, {"blue", "\033[34m"}, {"yellow", "\033[33m"}, {"reset", "\033[0m"}};

void gotoxy(size_t x, size_t y);

struct Pixel {
    char character;
    char const *color_code;

    bool operator==(Pixel const &compare);
    bool operator!=(Pixel const &compare);
};

using frame_matrix = std::vector<std::vector<Pixel>>;

class Frame {
private:
    void initialize_frame();

    bool is_valid_input(std::string const &height_start, std::string const &height_length, std::string const &range_start, std::string const &range_length, std::string const &printable_char, std::string const &color);

public:
    frame_matrix current_frame;
    const static size_t AMOUNT_OF_INPUT_OPTIONS = 6;
    const static size_t FRAME_WIDTH = 99;
    const static size_t FRAME_HEIGHT = 33;
    const static char INPUT_DELIMITER = ',';
    const static char BACKGROUND = '#';

    Frame();
    Frame(std::string const &input);

    frame_matrix get_current_frame() const;
    void alter_frame(std::string const &input);
    void set_current_frame(frame_matrix const &new_current_frame);
    void print_frame();
    void print_frame(Frame const &prev_frame);
    bool parse_input(std::string const &input);
};

class GraphicalVisualizer {
private:
    std::queue<Frame> frame_queue;

public:
    GraphicalVisualizer();

    std::queue<Frame> get_frame_queue() const;
    void add_frame(Frame frame);
    void print_sequence(const std::chrono::milliseconds millis);
    void print_sequence_no_clear(const std::chrono::milliseconds millis);
};

struct Input { // TODO: finish it
    size_t height_start;
    size_t height_length;
    size_t width_start;
    size_t width_length;
    char symbol;
    std::string color;
};