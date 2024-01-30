#pragma once

#include "falling_sand.hpp"
#include "graphical_visualizer.hpp"
#include <chrono>
#include <iterator>
#include <queue>
#include <string>

using namespace std::chrono_literals;

using grid = std::vector<std::pair<int, char const *>>; // represents the frame in heights of columns and remembers the color of the column
const std::chrono::milliseconds millis_per_frame_algo_vis = 50ms;

class AlgorithmVisualizer { // consists of the visualizer to print the frames, a frame that is changing and different kind of sorting algos that works on grid
private:
    GraphicalVisualizer visualizer;
    Frame to_sort;

public:
    AlgorithmVisualizer(Frame to_sort, char symbol);

    std::vector<std::pair<int, char const *>> frame_matrix_to_num(frame_matrix convert_from, char symbol_to_count);
    frame_matrix num_to_frame_matrix(std::vector<std::pair<int, char const *>> convert_from, char symbol_to_insert);

    void bubble_sort(grid &vect_to_sort, char symbol);
    void merge_sort(grid &vect_to_sort, char symbol);
    void merge_sort(grid &vect_to_sort, char symbol, size_t start, size_t end, std::vector<std::pair<int, char const *>> &printable_frame);
    void quick_sort(grid &vect_to_sort, char symbol, size_t start, size_t end);
};