#include "algorithm_visualizer.hpp"
#include <algorithm>
#include <iostream>
#include <random>

char const *generate_random_color() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, colors.size() - 1);
    auto it = colors.begin();
    for (size_t i = 0; i < dist(rng); ++i) {
        it++;
    }
    if (it->first == "reset")
        return colors.at("red");
    return it->second;
}

void change_frame_colors(Frame &frame_to_color, char symbol_to_color) {

    for (size_t j = 0; j < frame_to_color.current_frame[0].size(); ++j) {

        char const *color = generate_random_color();
        for (size_t i = 0; i < frame_to_color.current_frame.size(); ++i) {
            if (frame_to_color.current_frame[i][j].character == symbol_to_color)
                frame_to_color.current_frame[i][j].color_code = color;
        }
    }
}

AlgorithmVisualizer::AlgorithmVisualizer(Frame to_sort, char symbol) : to_sort(to_sort) {

    change_frame_colors(to_sort, SAND_SHAPE);
    grid frame_to_vec = frame_matrix_to_num(to_sort.current_frame, symbol);
    // bubble_sort(frame_to_vec, symbol);
    //  merge_sort(frame_to_vec, symbol);
    quick_sort(frame_to_vec, symbol, 0, frame_to_vec.size());
    system("clear");
    visualizer.print_sequence(millis_per_frame_algo_vis);
}

grid AlgorithmVisualizer::frame_matrix_to_num(frame_matrix convert_from, char symbol_to_count) {
    grid convert_to;
    for (size_t i = 0; i < convert_from[0].size(); ++i) {
        int symbol_counter = 0;
        char const *color = colors.at("reset");
        for (size_t j = 0; j < convert_from.size(); ++j) {
            if (convert_from[j][i].character == symbol_to_count) {
                symbol_counter++;
                color = convert_from[j][i].color_code;
            }
        }
        convert_to.push_back({symbol_counter, color});
    }
    return convert_to;
}

frame_matrix AlgorithmVisualizer::num_to_frame_matrix(grid convert_from, char symbol_to_insert) {
    frame_matrix convert_to;
    for (size_t i = 0; i < Frame::FRAME_HEIGHT; ++i) {
        std::vector<Pixel> line;
        for (size_t j = 0; j < Frame::FRAME_WIDTH; ++j)
            line.push_back({Frame::BACKGROUND, colors.at("reset")});

        convert_to.push_back(line);
    }

    int matrix_index = 0;
    for (auto height : convert_from) {
        if (height.first >= Frame::FRAME_HEIGHT)
            return {};
        for (int j = 0; j < height.first; ++j) {
            convert_to[convert_to.size() - j - 1][matrix_index] = {symbol_to_insert, height.second};
        }
        matrix_index++;
    }
    return convert_to;
}

void AlgorithmVisualizer::bubble_sort(grid &vect_to_sort, char symbol) {

    for (size_t i = 0; i < vect_to_sort.size() - 1; ++i) {
        bool is_swapped = false;
        for (size_t j = 0; j < vect_to_sort.size() - i - 1; ++j) {
            to_sort.set_current_frame(num_to_frame_matrix(vect_to_sort, symbol));
            visualizer.add_frame(to_sort);
            if (vect_to_sort[j].first >= vect_to_sort[j + 1].first) {
                std::swap(vect_to_sort[j], vect_to_sort[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped)
            break;
    }
}

void AlgorithmVisualizer::merge_sort(grid &vect_to_sort, char symbol) {
    if (vect_to_sort.size() <= 1)
        return;

    size_t mid = (vect_to_sort.size() / 2);
    grid left(vect_to_sort.cbegin(), vect_to_sort.cbegin() + mid);
    grid right(vect_to_sort.cbegin() + mid, vect_to_sort.cend());
    vect_to_sort.clear();
    merge_sort(left, symbol);
    merge_sort(right, symbol);

    size_t left_index = 0;
    size_t right_index = 0;
    while (vect_to_sort.size() < left.size() + right.size()) {
        if (left_index == left.size())
            vect_to_sort.insert(vect_to_sort.end(), right.begin() + right_index, right.end());
        else if (right_index == right.size())
            vect_to_sort.insert(vect_to_sort.end(), left.begin() + left_index, left.end());
        else {
            if (left[left_index].first > right[right_index].first) {
                vect_to_sort.push_back(left[left_index]);
                left_index++;
            } else {
                vect_to_sort.push_back(right[right_index]);
                right_index++;
            }
        }
    }

    to_sort.set_current_frame(num_to_frame_matrix(vect_to_sort, symbol));
    visualizer.add_frame(to_sort);
}

void AlgorithmVisualizer::merge_sort(grid &vect_to_sort, char symbol, size_t start, size_t end, grid &printable_frame) {
    if (vect_to_sort.size() <= 1)
        return;

    size_t mid = (vect_to_sort.size() / 2);
    grid left(vect_to_sort.cbegin(), vect_to_sort.cbegin() + mid);
    grid right(vect_to_sort.cbegin() + mid, vect_to_sort.cend());
    vect_to_sort.clear();
    merge_sort(left, symbol, start, mid, printable_frame);
    merge_sort(right, symbol, mid, end, printable_frame);

    size_t left_index = 0;
    size_t right_index = 0;
    while (vect_to_sort.size() < left.size() + right.size()) {
        if (left_index == left.size())
            vect_to_sort.insert(vect_to_sort.end(), right.begin() + right_index, right.end());
        else if (right_index == right.size())
            vect_to_sort.insert(vect_to_sort.end(), left.begin() + left_index, left.end());
        else {
            if (left[left_index].first > right[right_index].first) {
                vect_to_sort.push_back(left[left_index]);
                left_index++;
            } else {
                vect_to_sort.push_back(right[right_index]);
                right_index++;
            }
        }
    }

    for (size_t i = 0; i < vect_to_sort.size(); ++i) {
        if (start < end) {
            printable_frame[start] = vect_to_sort[i];
            start++;
        }
    }

    to_sort.set_current_frame(num_to_frame_matrix(printable_frame, symbol));
    visualizer.add_frame(to_sort);
}

void AlgorithmVisualizer::quick_sort(grid &vect_to_sort, char symbol, size_t start, size_t end) {
    if (end - start <= 0)
        return;

    size_t pivot = end - 1;
    size_t first_bigger_than_pivot = start;
    bool is_bigger_found = vect_to_sort[first_bigger_than_pivot].first > vect_to_sort[pivot].first;
    for (size_t i = start; i < pivot; ++i) {
        if (!is_bigger_found && vect_to_sort[i].first > vect_to_sort[pivot].first) {
            is_bigger_found = true;
            first_bigger_than_pivot = i;
        }
        if (is_bigger_found && vect_to_sort[i].first <= vect_to_sort[pivot].first) {
            std::rotate(vect_to_sort.begin() + first_bigger_than_pivot, vect_to_sort.begin() + i, vect_to_sort.begin() + i + 1);
            to_sort.set_current_frame(num_to_frame_matrix(vect_to_sort, symbol));
            visualizer.add_frame(to_sort);
            first_bigger_than_pivot += 1;
        }
    }

    if (is_bigger_found) {
        std::swap(vect_to_sort[pivot], vect_to_sort[first_bigger_than_pivot]);
        pivot = first_bigger_than_pivot;
        to_sort.set_current_frame(num_to_frame_matrix(vect_to_sort, symbol));
        visualizer.add_frame(to_sort);
    }

    quick_sort(vect_to_sort, symbol, start, pivot);
    quick_sort(vect_to_sort, symbol, pivot + 1, end);
}
