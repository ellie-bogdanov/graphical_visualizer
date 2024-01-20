#include <iostream>
#include <string>
#include <chrono>

#include "falling_sand.hpp"
#include "algorithm_visualizer.hpp"

using namespace std::chrono_literals;

// ANSI escape codes for text color

int main(int, char**)
{
    falling_sand simualtion;
    algorithm_visualizer algo_vis(simualtion.get_field(), SAND_SHAPE, SAND_DEFAULT_COLOR);


    
    return 0;
    
}
