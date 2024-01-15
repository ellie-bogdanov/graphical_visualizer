#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <thread>

#define frame_matrix std::vector<std::string>
using namespace std::chrono_literals;
class frame
{
private:

    
   frame_matrix current_frame;

public:
    frame(const frame_matrix& current_frame) : current_frame(current_frame)
    {
        
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

    void print_sequence()
    {
        std::queue<frame> local_temp_queue = frame_queue;
        
        while(!local_temp_queue.empty())
        {
            local_temp_queue.front().print_frame();
            local_temp_queue.pop();
            std::this_thread::sleep_for(500ms);
            system("cls");
        }
        
    }

};

int main(int, char**)
{
    graphical_visualizer visualizer;
    int sequence = 1;
    for(size_t i = 1; i <= 10; ++i)
    {
        frame_matrix current_frame;
        std::string str;
        if(sequence % 2 == 0)
            str = "@#@#@#@#@#";
        else
            str = "#@#@#@#@#@";
        for(size_t j = 1; j <= 10; ++j)
            current_frame.push_back(str);
        frame f(current_frame);
        visualizer.add_frame(f);
        sequence++;
    }
    visualizer.print_sequence();

    return 0;
    
}
