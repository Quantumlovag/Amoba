#include "kp_numeric_editor.hpp"
#include "graphics.hpp"
#include <sstream>

using namespace genv;

Numeric_Editor::Numeric_Editor(float p_x, float p_y, float s_x, float s_y, int mini, int maxi)
    :Widgets(p_x, p_y, s_x, s_y)
{
    minimum=mini;
    maximum=maxi;
    number=mini;
}

void Numeric_Editor::print() const
{
    canvas dnum;
    dnum.open(size_x, size_y);
    std::stringstream s;
    s << number;
    dnum << move_to(0, 0) << color(0, 0, 0) << box(size_x, size_y)
         << move_to(1, 1) << color(255, 255, 255) << box(size_x-2, size_y-2)
         << move_to(size_x-20, 0) << color(0, 0, 0) << box(20, size_y)
         << move_to(size_x-20, size_y/2) << color(255, 255, 255) << line_to(size_x, size_y/2)
         << move_to(size_x-20, size_y/2) << color(255, 255, 255) << line_to(size_x-10, 0)
         << move_to(size_x-20, size_y/2) << color(255, 255, 255) << line_to(size_x-10, size_y-1)
         << move_to(size_x-10, 0) << color(255, 255, 255) << line_to(size_x, size_y/2)
         << move_to(size_x-10, size_y-1) << color(255, 255, 255) << line_to(size_x, size_y/2)
         << move_to(10, size_y/2+gout.cascent()/2) << color(0, 0, 0) << text(s.str());
    gout << stamp(dnum, pos_x, pos_y);
    if(focused)
    {
        gout << move_to(pos_x-10, pos_y-10);
        for(int i=pos_x-10; i<pos_x+size_x+10; i++)
        {
            if(i%2==0) gout << color(255, 255, 255) << line_to(i, pos_y-10);
            if(i%2==1) gout << color(0, 0, 0) << line_to(i, pos_y-10);
        }
        for(int i=pos_y-10; i<pos_y+size_y+10; i++)
        {
            if(i%2==0) gout << color(255, 255, 255) << line_to(pos_x+size_x+10, i);
            if(i%2==1) gout << color(0, 0, 0) << line_to(pos_x+size_x+10, i);
        }
        for(int i=pos_x+size_x+10; i>pos_x-10; i--)
        {
            if(i%2==0) gout << color(255, 255, 255) << line_to(i, pos_y+size_y+10);
            if(i%2==1) gout << color(0, 0, 0) << line_to(i, pos_y+size_y+10);
        }
        for(int i=pos_y+size_y+10; i>pos_y-10; i--)
        {
            if(i%2==0) gout << color(255, 255, 255) << line_to(pos_x-10, i);
            if(i%2==1) gout << color(0, 0, 0) << line_to(pos_x-10, i);
        }
    }
}

void Numeric_Editor::handle(event ev)
{
    if(ev.button==btn_left && ev.pos_x>=pos_x+size_x-20 && ev.pos_x<=pos_x+size_x && ev.pos_y<=pos_y+size_y/2 && ev.pos_y>=pos_y && number!=maximum)
    {
        number++;
    }
    if(ev.button==btn_left && ev.pos_x>=pos_x+size_x-20 && ev.pos_x<=pos_x+size_x && ev.pos_y>=pos_y+size_y/2 && ev.pos_y<=pos_y+size_y && number!=minimum)
    {
        number--;
    }
    if(focused && (ev.keycode==key_up || ev.keycode==key_pgup) && number!=maximum)
    {
        number++;
    }
    if(focused && (ev.keycode==key_down || ev.keycode==key_pgdn) && number!=minimum)
    {
        number--;
    }
}
