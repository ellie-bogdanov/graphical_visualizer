#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <thread>
#include <sstream>

#define frame_matrix std::vector<std::string>
using namespace std::chrono_literals;



class frame
{
private:

    
   frame_matrix current_frame; 

public:
    const static size_t AMOUNT_OF_SECTIONS = 5;
    const static size_t WIDTH = 10;
    const static size_t HEIGHT = 10;
    const static char DELIMITER = ',';
    const static char background = '#';
    bool is_valid;

    frame(const std::string& input)
    {
        
        initialize_frame();
        is_valid = parse_input(input);   
        
    }

    frame_matrix get_current_frame() const
    {
        return current_frame;
    }

    void set_current_array(const frame_matrix& new_current_frame)
    {
        current_frame = new_current_frame;
    }
    
    void print_frame()
    {
        for(const std::string& line : current_frame)
        {
            std::cout << line << std::endl;
        }
    }

    bool parse_input(const std::string& input)
    {

        std::stringstream input_stream(input);
        std::string input_sections[AMOUNT_OF_SECTIONS];
        
        size_t input_sections_index = 0;
        while(std::getline(input_stream, input_sections[input_sections_index], DELIMITER))
            ++input_sections_index;

        if(!is_valid_input(input_sections[0], input_sections[1], input_sections[2], input_sections[3], input_sections[4]))
        {
            return false;
        }
        
        int height_start = std::stoi(input_sections[0]);
        int height_length = std::stoi(input_sections[1]);
        int range_start = std::stoi(input_sections[2]);
        int range_length = std::stoi(input_sections[3]);
        
        char printable_char = input_sections[4][0];        //should always be a string of length 1

        for(size_t i = height_start; i < height_start + height_length - 1; ++i)
        {
            for(size_t j = range_start; j < range_start + range_length - 1; ++j)
            {
                current_frame[i][j] = printable_char;
            }
        }
        
        return true;
    }

    void initialize_frame()
    {
        for(size_t i = 0; i < HEIGHT; ++i)
        {
            std::string line;
            for(size_t j = 0; j < WIDTH; ++j)
                line += background;
            current_frame.push_back(line);
        } 
    }
    bool is_a_number(std::string number)
    {
        for(const char& ch : number)
        {
            if(!std::isdigit(ch))
                return false;
        }
        
        return true;
    }
    bool is_valid_input(std::string height_start, std::string height_length, std::string range_start, std::string range_length, std::string printable_char)
    {
        if(!is_a_number(height_start) || !is_a_number(height_start) || !is_a_number(height_start) || !is_a_number(height_start))
        {
            return false;
        }
        if(printable_char.size() != 1)
            return false;

        int height_start_int = std::stoi(height_start);
        int height_length_int = std::stoi(height_length);
        int range_start_int = std::stoi(range_start);
        int range_length_int = std::stoi(range_length);

        if(height_start_int < 0 || height_length_int + height_length_int - 1 >= HEIGHT || range_start_int < 0 || range_start_int + range_length_int - 1 >= WIDTH)
            return false;   
        return true;
    }
};

class graphical_visualizer
{
private:
    std::queue<frame> frame_queue;

public:
    graphical_visualizer()
    {
        frame_queue = {};
    }

    std::queue<frame> get_frame_queue() const
    {
        return frame_queue;
    }
    void add_frame(const frame& frame)
    {
        frame_queue.push(frame);
    }

    void print_sequence(const std::chrono::milliseconds millis)
    {
        std::queue<frame> local_temp_queue = frame_queue;


        while(!local_temp_queue.empty())
        {            
            local_temp_queue.front().print_frame();
            local_temp_queue.pop();
            std::cout << std::endl;   
            std::this_thread::sleep_for(10000ms);
            printf("\033c");
        }

        
        
    }

};

int main(int, char**)
{
    graphical_visualizer visualizer;

    size_t amount_of_frames;
    std::cout << "enter amount of frames: ";
    std::cin >> amount_of_frames;
    printf("\033c");
    const std::chrono::milliseconds millis_for_frame = 1000ms;
    

    for(size_t i = 0; i < amount_of_frames; ++i)
    {

        std::string input;
        std::cout << "enter the parameters ( height_start,height_length,range_start,range_length,char ): " << std::endl;
        std::cin >> input;
        frame new_frame(input);

        if(!new_frame.is_valid)
        {
            std::cout << "frame number {" << i + 1 << "} failed" << std::endl;
        }
        else
        {
            visualizer.add_frame({input});
        }
        //printf("\033c");
        
    }

    printf("\033c");
    visualizer.print_sequence(millis_for_frame);

    return 0;
    
}
