#ifndef KP_WINDOW_HPP_INCLUDED
#define KP_WINDOW_HPP_INCLUDED
#include "kp_widgets.hpp"
#include <vector>

class Window
{
protected:
    int X, Y;
    bool exit;
    std::vector<Widgets *> v_widgets;
public:
    Window(int inX, int inY);
    void events();
    void shutdown();
    void add(Widgets *w);
};

#endif // KP_WINDOW_HPP_INCLUDED
