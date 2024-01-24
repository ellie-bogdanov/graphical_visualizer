#include "algorithm_visualizer.hpp"
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
    std::vector<std::pair<int, char const *>> frame_to_vec = frame_matrix_to_num(to_sort.current_frame, symbol);
    bubble_sort(frame_to_vec, symbol);
    visualizer.print_sequence(millis_per_frame_algo_vis);
}

std::vector<std::pair<int, char const *>> AlgorithmVisualizer::frame_matrix_to_num(frame_matrix convert_from, char symbol_to_count) {
    std::vector<std::pair<int, char const *>> convert_to;
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

frame_matrix AlgorithmVisualizer::num_to_frame_matrix(std::vector<std::pair<int, char const *>> convert_from, char symbol_to_insert) {
    frame_matrix convert_to;
    for (size_t i = 0; i < Frame::FRAME_HEIGHT; ++i) {
        std::vector<pixel> line;
        for (size_t j = 0; j < Frame::FRAME_WIDTH; ++j)
            line.push_back({'#', colors.at("reset")});

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

void AlgorithmVisualizer::bubble_sort(std::vector<std::pair<int, char const *>> &vect_to_sort, char symbol) {
    Frame new_frame = to_sort;

    for (size_t i = 0; i < vect_to_sort.size() - 1; ++i) {
        bool is_swapped = false;
        for (size_t j = 0; j < vect_to_sort.size() - i - 1; ++j) {
            new_frame.set_current_frame(num_to_frame_matrix(vect_to_sort, symbol));
            visualizer.add_frame(new_frame);
            if (vect_to_sort[j].first >= vect_to_sort[j + 1].first) {
                std::swap(vect_to_sort[j], vect_to_sort[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped)
            break;
    }
}