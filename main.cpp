#include <iostream>
#include <string>
#include <array>
#include <queue>


class frame
{
private:
    const static size_t FRAME_WIDTH = 30;
    const static size_t FRAME_HEIGHT = 30;
    
    std::array<std::array<std::string, FRAME_WIDTH>, FRAME_HEIGHT> current_frame;

public:
    frame(const std::array<std::array<std::string, FRAME_WIDTH>, FRAME_HEIGHT> current_frame) : current_frame(current_frame)
    {
        
    }

    std::array<std::array<std::string, FRAME_WIDTH>, FRAME_HEIGHT> get_current_frame() const
    {
        return current_frame;
    }

    void set_current_array(const std::array<std::array<std::string, FRAME_WIDTH>, FRAME_HEIGHT>& new_current_frame)
    {
        current_frame = new_current_frame;
    }
    
};

class graphical_visualizer
{
    
};

int main(int, char**){
    std::array<std::array<std::string, 30>, 30> current_frame;
    frame f(current_frame);
    f.get_current_frame();
}
