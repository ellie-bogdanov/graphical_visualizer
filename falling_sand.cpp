#include "falling_sand.hpp"

#include <random>

int generate_random_length()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(MIN_SAND_LENGTH, MAX_SAND_LENGTH); // distribution in range [MIN_SAND_LENGTH, MAX_SAND_LENGTH]

    return dist(rng);
}

int generate_random_start_pos(int sand_length)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, frame::WIDTH - sand_length - 1);

    return dist(rng);
}

sand_block::sand_block()
{
    length = generate_random_length();
    starting_position = generate_random_start_pos(length);
    shape = SAND_SHAPE;
    color = SAND_DEFAULT_COLOR;
    for(size_t i = starting_position; i <= starting_position + length - 1; ++i )
    {
        links.push_back({0, i});
    }
}

sand_block::sand_block(std::string color) : color(color)
{
    length = generate_random_length();
    starting_position = generate_random_start_pos(length);
    shape = SAND_SHAPE;
    for(size_t i = starting_position; i <= starting_position + length - 1; ++i )
    {
        links.push_back({0, i});
    }
}

falling_sand::falling_sand()
{   
    generate_sand_blocks();
    simulate_fall();
    visualizer.print_sequence(millis_for_frame);
}

void falling_sand::generate_sand_blocks()
{
    for(size_t i = 1; i <= SAND_BLOCK_AMOUNT; ++i)
    {
        
        sand_blocks.push(sand_block());
    }
}

void falling_sand::simulate_fall()
{
    
    while(!sand_blocks.empty())
    {
        sand_block current_block = sand_blocks.front();
        field.alter_frame("0,1," + std::to_string(current_block.starting_position) + std::to_string(current_block.length) + current_block.shape + current_block.color);
        while (!current_block.links.empty())
        {
            visualizer.add_frame(field);
            std::vector<size_t> links_to_remove;
            frame_matrix new_frame = field.get_current_frame();
            for(size_t i = 0; i < current_block.links.size(); ++i)
            {
                std::pair<size_t, size_t> link = current_block.links[i];
                if(link.first == frame::HEIGHT - 1 || field.get_current_frame()[link.first + 1][link.second].first != current_block.shape)
                    links_to_remove.push_back(i);
                else
                {    
                    
                    new_frame[current_block.links[i].first][current_block.links[i].second] = {'#', colors.at("reset")};
                    current_block.links[i].first += 1;
                    new_frame[current_block.links[i].first][current_block.links[i].second] = {current_block.shape, colors.at(current_block.color)};    
                }
            }
            for(size_t link_to_remove : links_to_remove)
                current_block.links.erase(current_block.links.begin() + link_to_remove); 
            field.set_current_frame(new_frame);
        }
        sand_blocks.pop();
    }
}


