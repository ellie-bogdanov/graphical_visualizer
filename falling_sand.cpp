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
}

sand_block::sand_block(std::string color) : color(color)
{
    length = generate_random_length();
    starting_position = generate_random_start_pos(length);
    shape = SAND_SHAPE;
}

falling_sand::falling_sand()
{
    field.initialize_frame();    
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
    
    for(size_t i = 0; i < sand_blocks.size(); ++i)
    {
        sand_block current_block = sand_blocks.front();
        field.alter_frame("0,1," + std::to_string(current_block.starting_position) + std::to_string(current_block.length) + current_block.shape + current_block.color);
        // TODO: finish
    }
}
