#include "graphical_visualizer.hpp"

#include <iostream>
#include <sstream>
#include <thread>

frame::frame()
{
    initialize_frame();
}

frame::frame(const std::string& input)
{
    initialize_frame();
    alter_frame(input); 
}

frame_matrix frame::get_current_frame() const
{
    return current_frame;
}

void frame::alter_frame(const std::string& input)
{
    is_valid = parse_input(input);
}

void frame::set_current_frame(const frame_matrix& new_current_frame)
{
    current_frame = new_current_frame;
}

void frame::print_frame()
{
    for(const std::vector<std::pair<char, std::string>>& line : current_frame)
    {
        for(const std::pair<char, std::string>& current_char : line)
        {
            std::cout << colors.at(current_char.second) << current_char.first;
            std::cout << colors.at("reset");
        }
        std::cout << std::endl;
    }
}

bool frame::parse_input(const std::string& input)
{
    std::stringstream input_stream(input);
    std::string input_sections[AMOUNT_OF_SECTIONS];
    
    size_t input_sections_index = 0;
    while(std::getline(input_stream, input_sections[input_sections_index], DELIMITER))
        ++input_sections_index;

    if(!is_valid_input(input_sections[0], input_sections[1], input_sections[2], input_sections[3], input_sections[4], input_sections[5]))
    {
        return false;
    }
    
    int height_start = std::stoi(input_sections[0]);
    int height_length = std::stoi(input_sections[1]);
    int range_start = std::stoi(input_sections[2]);
    int range_length = std::stoi(input_sections[3]);
    std::string color = colors.at(input_sections[5]);

    
    char printable_char = input_sections[4][0];        //should always be a string of length 1

    for(size_t i = height_start; i <= height_start + height_length - 1; ++i)
    {
        for(size_t j = range_start; j <= range_start + range_length - 1; ++j)
        {
            current_frame[i][j].first = printable_char;
            current_frame[i][j].second = color;
        }
    }
    
    return true;
}

void frame::initialize_frame()
{
    for(size_t i = 0; i < HEIGHT; ++i)
    {
        std::vector<std::pair<char, std::string>> line;
        for(size_t j = 0; j < WIDTH; ++j)
            line.push_back({'#', colors.at("reset")});

        current_frame.push_back(line);
    } 
}

bool is_a_number(std::string number)
{
    for(const char& ch : number)
    {
        if(!std::isdigit(ch))
            return false;
    }
    
    return true;
}

bool frame::is_valid_input(std::string height_start, std::string height_length, std::string range_start, std::string range_length, std::string printable_char,std::string color)
{
    std::unordered_map<std::string, std::string>::const_iterator pos = colors.find(color);
    if(pos == colors.end())
        return false;

    if(!is_a_number(height_start) || !is_a_number(height_start) || !is_a_number(height_start) || !is_a_number(height_start))
    {
        return false;
    }
    if(printable_char.size() != 1)
        return false;

    int height_start_int = std::stoi(height_start);
    int height_length_int = std::stoi(height_length);
    int range_start_int = std::stoi(range_start);
    int range_length_int = std::stoi(range_length);

    if(height_start_int < 0 || height_length_int + height_length_int - 1 >= HEIGHT || range_start_int < 0 || range_start_int + range_length_int - 1 >= WIDTH)
        return false;   
    return true;
}

graphical_visualizer::graphical_visualizer()
{
    frame_queue = {};
}

std::queue<frame> graphical_visualizer::get_frame_queue() const
{
    return frame_queue;
}

void graphical_visualizer::add_frame(frame frame)
{
    frame_queue.push(frame);
}

void graphical_visualizer::print_sequence(const std::chrono::milliseconds millis)
{
    std::queue<frame> local_temp_queue = frame_queue;


    while(!local_temp_queue.empty())
    {            
        local_temp_queue.front().print_frame();
        local_temp_queue.pop();
        std::this_thread::sleep_for(millis);
        system("clear");
    }

}