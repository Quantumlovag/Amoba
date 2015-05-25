#include "kp_widgets.hpp"
#include "graphics.hpp"

using namespace genv;

Widgets::Widgets(float p_x, float p_y, float s_x, float s_y)
{
    pos_x=p_x, pos_y=p_y;
    size_x=s_x, size_y=s_y;
    focused=false;
}

void Widgets::focus()
{
    focused=true;
}

void Widgets::unfocus()
{
    focused=false;
}

bool Widgets::contains(event ev)
{
    return (ev.pos_x>=pos_x && ev.pos_x<=pos_x+size_x && ev.pos_y>=pos_y && ev.pos_y<=pos_y+size_y);
}
