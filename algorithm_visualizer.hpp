#pragma once

#include "falling_sand.hpp"
#include "graphical_visualizer.hpp"
#include <chrono>
#include <iterator>
#include <queue>
#include <string>

using namespace std::chrono_literals;

using grid = std::vector<std::pair<int, char const *>>; // represents the frame in heights of columns and remembers the color of the column
namespace algo_vis {
    const std::chrono::milliseconds MILLIS_PER_FRAME = 50ms;

    char const *generate_random_color();
    void change_frame_colors(Frame &frame_to_color, char symbol_to_color);
}

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