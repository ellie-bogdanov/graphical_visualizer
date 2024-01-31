#include <chrono>
#include <iostream>
#include <string>

#include "algorithm_visualizer.hpp"
#include "falling_sand.hpp"
#include "game_of_life.hpp"

using namespace std::chrono_literals;

// ANSI escape codes for text color

int main(int, char **) {

    auto start = std::chrono::high_resolution_clock::now();

    // FallingSand simualtion;
    // AlgorithmVisualizer algo_vis(simualtion.get_field(), SAND_SHAPE);

    Frame frame;
    simulate_game_of_life(frame, 100, &glider_gun_conf);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

    return 0;
}
