#include "algorithm_visualizer.hpp"
#include <random>


std::string generate_random_color()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, colors.size() - 1); 
    auto it = colors.begin();
    for(size_t i = 0; i < dist(rng); ++i)
    {
        it++;
    }
    if(it->first == "reset")
        return "red";
    return it->first;
}

void change_frame_colors(frame& frame_to_color, char symbol_to_color)
{
    
    for(size_t j = 0; j< frame_to_color.current_frame[0].size(); ++j)
    {

        std::string color = generate_random_color();
        for(size_t i = 0; i < frame_to_color.current_frame.size(); ++i)
        {
            if(frame_to_color.current_frame[i][j].first == symbol_to_color)
                frame_to_color.current_frame[i][j].second = color;
        }
    }
}

algorithm_visualizer::algorithm_visualizer(frame to_sort, char symbol) : to_sort(to_sort)
{
    
    change_frame_colors(to_sort, SAND_SHAPE);
    std::vector<std::pair<int, std::string>> frame_to_vec = frame_matrix_to_num(to_sort.current_frame, symbol);
    bubble_sort(frame_to_vec, symbol);
    visualizer.print_sequence(millis_per_frame_algo_vis);
}

std::vector<std::pair<int, std::string>> algorithm_visualizer::frame_matrix_to_num(frame_matrix convert_from, char symbol_to_count)
{
    std::vector<std::pair<int, std::string>> convert_to;
    for(size_t i = 0; i < convert_from[0].size(); ++i)
    {
        int symbol_counter = 0;
        std::string color = "reset";
        for(size_t j = 0; j < convert_from.size(); ++j)
        {
            if(convert_from[j][i].first == symbol_to_count)
            {    
                symbol_counter++;
                color = convert_from[j][i].second;
            }
        }
        convert_to.push_back({symbol_counter, color});
    }
    return convert_to;
}

frame_matrix algorithm_visualizer::num_to_frame_matrix(std::vector<std::pair<int, std::string>> convert_from, char symbol_to_insert)
{
    frame_matrix conver_to;
    for(size_t i = 0; i < frame::FRAME_HEIGHT; ++i)
    {
        std::vector<std::pair<char, std::string>> line;
        for(size_t j = 0; j < frame::FRAME_WIDTH; ++j)
            line.push_back({'#', colors.at("reset")});

        conver_to.push_back(line);
    }

    int matrix_index = 0;
    for(std::pair<int, std::string> height : convert_from)
    {
        if(height.first >= frame::FRAME_HEIGHT)
            return {};
        for(int j = 0; j < height.first; ++j)
        {
            conver_to[conver_to.size() - j - 1][matrix_index] = {symbol_to_insert, colors.at(height.second)};
            
        }
        matrix_index++;
    }
    return conver_to;
}

void algorithm_visualizer::bubble_sort(std::vector<std::pair<int, std::string>>& vect_to_sort, char symbol)
{
    frame new_frame = to_sort;
    
    for(size_t i = 0; i < vect_to_sort.size() - 1; ++i)
    {
        bool is_swapped = false;
        for(size_t j = 0; j < vect_to_sort.size() - i - 1; ++j)
        {
            new_frame.set_current_frame(num_to_frame_matrix(vect_to_sort, symbol));
            visualizer.add_frame(new_frame);
            if(vect_to_sort[j].first > vect_to_sort[j + 1].first)
            {
                std::swap(vect_to_sort[j], vect_to_sort[j + 1]);
                is_swapped = true;
            }
        }
        if(!is_swapped)
            break;
    }
}