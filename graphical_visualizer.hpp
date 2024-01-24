#pragma once

#include <chrono>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, char const *> colors = {{"red", "\033[31m"}, {"green", "\033[32m"}, {"blue", "\033[34m"}, {"yellow", "\033[33m"}, {"reset", "\033[0m"}};

struct Pixel {
    char character;
    char const *color_code;

    Pixel &operator=(Pixel const &new_pixel);
};

struct FrameMatrix {
private:
    std::vector<Pixel> frame_matrix;

public:
    size_t height;
    size_t width;

    FrameMatrix();

    Pixel &at(size_t height_index, size_t width_index);
    void set(size_t height_index, size_t width_index, Pixel const &new_pixel);
    void push_back_line(std::vector<Pixel> const &line);
    size_t size();
};

// using frame_matrix = std::vector<std::vector<pixel>>;

class Frame {
private:
    void initialize_frame();

    bool is_valid_input(std::string const &height_start, std::string const &height_length, std::string const &range_start, std::string const &range_length, std::string const &printable_char, std::string const &color);

public:
    FrameMatrix frame_matrix;
    const static size_t AMOUNT_OF_INPUT_OPTIONS = 6;
    const static size_t FRAME_WIDTH = 30;
    const static size_t FRAME_HEIGHT = 10;
    const static char INPUT_DELIMITER = ',';
    const static char BACKGROUND = '#';

    Frame();
    Frame(std::string const &input);

    FrameMatrix get_current_frame() const;
    void alter_frame(std::string const &input);
    void set_current_frame(FrameMatrix const &new_current_frame);
    void print_frame();
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
};

struct input {
    size_t height_start;
    size_t height_length;
    size_t width_start;
    size_t width_length;
    char symbol;
    std::string color;
};