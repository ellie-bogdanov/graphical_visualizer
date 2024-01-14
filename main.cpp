#include <iostream>
#include <string>
#include <array>
#include <queue>

const static size_t FRAME_WIDTH = 30;
const static size_t FRAME_HEIGHT = 30;
#define frame_matrix std::array<std::array<std::string, FRAME_WIDTH>, FRAME_HEIGHT> 
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

};

int main(int, char**){
    frame_matrix current_frame;
    frame f(current_frame);
    f.get_current_frame();
}
