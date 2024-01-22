#pragma once

#include <vector>
#include <string>
#include <queue>
#include <chrono>
#include <unordered_map>
#include <map>

const std::unordered_map<std::string, std::string> colors = {{"red", "\033[31m"}, {"green", "\033[32m"}, {"blue", "\033[34m"}, {"yellow", "\033[33m"}, {"reset", "\033[0m"}};

struct pixel
{
    char character;
    std::string color_code;
};


using frame_matrix = std::vector<std::vector<pixel>>;

class frame
{
private:
    
    void initialize_frame();

public:
    frame_matrix current_frame; 
    constexpr static size_t AMOUNT_OF_INPUT_OPTIONS = 6;
    constexpr static size_t FRAME_WIDTH = 30;
    constexpr static size_t FRAME_HEIGHT = 20;
    constexpr static char INPUT_DELIMITER = ',';
    constexpr static char BACKGROUND = '#';

    frame();
    frame(std::string const& input);

    frame_matrix get_current_frame() const;
    void alter_frame(std::string const& input);
    void set_current_frame(frame_matrix const& new_current_frame);
    void print_frame();
    bool parse_input(std::string const& input);
    
    bool is_valid_input(std::string height_start, std::string height_length, std::string range_start, std::string range_length, std::string printable_char,std::string color);

};

class graphical_visualizer
{
private:
    std::queue<frame> frame_queue;

public:
    graphical_visualizer();

    std::queue<frame> get_frame_queue() const;
    void add_frame(frame frame);
    void print_sequence(const std::chrono::milliseconds millis);

};

struct input
{
    size_t height_start;
    size_t height_length;
    size_t width_start;
    size_t width_length;
    char symbol;
    std::string color;
};