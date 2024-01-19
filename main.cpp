#include <iostream>
#include <string>
#include <chrono>

#include "falling_sand.hpp"

using namespace std::chrono_literals;

// ANSI escape codes for text color

int main(int, char**)
{
    falling_sand simualtion;
    /*
    graphical_visualizer visualizer;

    size_t amount_of_frames;
    std::cout << "enter amount of frames: ";
    std::cin >> amount_of_frames;
    system("clear");
    const std::chrono::milliseconds millis_for_frame = 5000ms;

    frame new_frame;
    for(size_t i = 0; i < amount_of_frames; ++i)
    {

        std::string input;
        std::cout << "enter the parameters ( height_start,height_length,range_start,range_length,char,color ): " << std::endl;
        std::cin >> input;
        new_frame.alter_frame(input);
        
        
    }
    visualizer.add_frame(new_frame);
    system("clear");
    visualizer.print_sequence(millis_for_frame);
    */
    return 0;
    
}
