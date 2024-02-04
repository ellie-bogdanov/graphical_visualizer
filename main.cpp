#include <chrono>

#include <iostream>
#include <string>
#include <thread>

#include "algorithm_visualizer.hpp"
#include "falling_sand.hpp"
#include "game_of_life.hpp"

using namespace std::chrono_literals;

int main(int, char **) {

    auto start = std::chrono::high_resolution_clock::now();

    FallingSand simualtion;
    std::this_thread::sleep_for(5000ms);
    AlgorithmVisualizer algo_vis(simualtion.get_field(), SAND_SHAPE);
    std::this_thread::sleep_for(5000ms);
    Frame frame;
    simulate_game_of_life(frame, 200, &glider_gun_conf);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

    return 0;
}
