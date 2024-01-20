#pragma once

#include "graphical_visualizer.hpp"
#include "falling_sand.hpp"
#include <queue>
#include <chrono>

using namespace std::chrono_literals;

const std::chrono::milliseconds millis_per_frame_algo_vis = 50ms; 

class algorithm_visualizer
{
private:
    graphical_visualizer visualizer;
    const frame to_sort;

public:

    algorithm_visualizer(frame to_sort, char symbol, std::string color);

    std::vector<int> frame_matrix_to_num(frame_matrix convert_from, char symbol_to_count);
    frame_matrix num_to_frame_matrix(std::vector<int> convert_from, char symbol_to_insert, std::string color);

    void bubble_sort(std::vector<int>& vect_to_sort, char symbol, std::string color);


};