#pragma once

#include "graphical_visualizer.hpp"
#include "falling_sand.hpp"
#include <queue>
#include <chrono>
#include <string>

using namespace std::chrono_literals;

const std::chrono::milliseconds millis_per_frame_algo_vis = 50ms; 

class algorithm_visualizer
{
private:
    graphical_visualizer visualizer;
    const frame to_sort;

public:

    algorithm_visualizer(frame to_sort, char symbol);

    std::vector<std::pair<int, char const*>> frame_matrix_to_num(frame_matrix convert_from, char symbol_to_count);
    frame_matrix num_to_frame_matrix(std::vector<std::pair<int, char const*>> convert_from, char symbol_to_insert);

    void bubble_sort(std::vector<std::pair<int, char const*>>& vect_to_sort, char symbol);


};