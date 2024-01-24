#include <chrono>
#include <iostream>
#include <string>

#include "algorithm_visualizer.hpp"
#include "falling_sand.hpp"

using namespace std::chrono_literals;

// ANSI escape codes for text color

int main(int, char **) {
    auto start = std::chrono::high_resolution_clock::now();

    FallingSand simualtion;
    AlgorithmVisualizer algo_vis(simualtion.get_field(), SAND_SHAPE);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

    return 0;
}
