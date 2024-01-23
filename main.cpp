#include <chrono>
#include <iostream>
#include <string>

#include "algorithm_visualizer.hpp"
#include "falling_sand.hpp"

using namespace std::chrono_literals;

// ANSI escape codes for text color

int main(int, char **) {
    FallingSand simualtion;
    AlgorithmVisualizer algo_vis(simualtion.get_field(), SAND_SHAPE);

    return 0;
}
