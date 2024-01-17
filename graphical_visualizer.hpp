#pragma once

#include <vector>
#include <string>
#include <queue>
#include <chrono>
#include <unordered_map>

using frame_matrix = std::vector<std::vector<std::pair<char, std::string>>>;
const std::unordered_map<std::string, std::string> colors = {{"red", "\033[31m"}, {"green", "\033[32m"}, {"blue", "\033[34m"}, {"yellow", "\033[33m"}, {"reset", "\033[0m"}};



class frame
{
private:

    std::string color;
    frame_matrix current_frame; 

public:
    const static size_t AMOUNT_OF_SECTIONS = 6;
    const static size_t WIDTH = 10;
    const static size_t HEIGHT = 10;
    const static char DELIMITER = ',';
    const static char background = '#';
    bool is_valid;

    frame();
    frame(const std::string& input);

    frame_matrix get_current_frame() const;
    void alter_frame(const std::string& input);
    void set_current_frame(const frame_matrix& new_current_frame);
    void print_frame();
    bool parse_input(const std::string& input);
    void initialize_frame();
    bool is_valid_input(std::string height_start, std::string height_length, std::string range_start, std::string range_length, std::string printable_char,std::string color);

};

class graphical_visualizer
{
private:
    std::queue<frame> frame_queue;

public:
    graphical_visualizer();

    std::queue<frame> get_frame_queue() const;
    void add_frame(const frame& frame);
    void print_sequence(const std::chrono::milliseconds millis);

};