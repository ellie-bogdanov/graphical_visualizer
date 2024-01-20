#include "algorithm_visualizer.hpp"

algorithm_visualizer::algorithm_visualizer(frame to_sort, char symbol, std::string color) : to_sort(to_sort)
{
    std::vector<int> frame_to_vec = frame_matrix_to_num(to_sort.get_current_frame(), symbol);
    bubble_sort(frame_to_vec, symbol, color);
    visualizer.print_sequence(millis_per_frame_algo_vis);
}

std::vector<int> algorithm_visualizer::frame_matrix_to_num(frame_matrix convert_from, char symbol_to_count)
{
    std::vector<int> convert_to;
    for(size_t i = 0; i < convert_from[0].size(); ++i)
    {
        int symbol_counter = 0;
        for(size_t j = 0; j < convert_from.size(); ++j)
        {
            if(convert_from[j][i].first == symbol_to_count)
                symbol_counter++;
        }
        convert_to.push_back(symbol_counter);
    }
    return convert_to;
}

frame_matrix algorithm_visualizer::num_to_frame_matrix(std::vector<int> convert_from, char symbol_to_insert, std::string color)
{
    frame_matrix conver_to;
    for(size_t i = 0; i < frame::HEIGHT; ++i)
    {
        std::vector<std::pair<char, std::string>> line;
        for(size_t j = 0; j < frame::WIDTH; ++j)
            line.push_back({'#', colors.at("reset")});

        conver_to.push_back(line);
    }

    int matrix_index = 0;
    for(int i : convert_from)
    {
        if(i >= frame::HEIGHT)
            return {};
        for(int j = 0; j < i; ++j)
        {
            conver_to[matrix_index][j] = {symbol_to_insert, colors.at(color)};
        }
    }
    return conver_to;
}

void algorithm_visualizer::bubble_sort(std::vector<int>& vect_to_sort, char symbol, std::string color)
{
    frame new_frame = to_sort;
    for(size_t i = 0; i < vect_to_sort.size() - 1; ++i)
    {
        bool is_swapped = false;
        for(size_t j = 0; j < vect_to_sort.size() - i - 1; ++j)
        {
            new_frame.set_current_frame(num_to_frame_matrix(vect_to_sort, symbol, color));
            visualizer.add_frame(new_frame);
            if(vect_to_sort[j] > vect_to_sort[j + 1])
            {
                std::swap(vect_to_sort[j], vect_to_sort[j + 1]);
                is_swapped = true;
            }
        }
        if(!is_swapped)
            break;
    }
}