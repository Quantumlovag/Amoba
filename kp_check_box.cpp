#include "kp_check_box.hpp"
#include "graphics.hpp"

using namespace genv;

Check_Box::Check_Box(float p_x, float p_y, float s_x, float s_y)
    : Widgets(p_x, p_y, s_x, s_y)
{
    marked=false;
}

void Check_Box::print() const
{
    canvas mbox;
    mbox.open(size_x, size_y);
    mbox << move_to(0, 0) << color(0, 0, 0) << box(size_x, size_y)
         << move_to(1, 1) << color(255, 255, 255) << box(size_x-2, size_y-2);
    if(marked)
    {
        mbox << move_to(0, 0) << color(0, 0, 0) << line_to(size_x, size_y)
             << line_to(size_x, 0) << color(0, 0, 0) << line_to(0, size_y);
    }
    gout << stamp(mbox, pos_x, pos_y);
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

void Check_Box::handle(event ev)
{
    if(ev.button==btn_left && contains(ev))
    {
        marked=!marked;
    }
    if(ev.keycode==key_enter)
    {
        marked=!marked;
    }
}
