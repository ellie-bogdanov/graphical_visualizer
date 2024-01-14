#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define frame_matrix std::vector<std::string>
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
