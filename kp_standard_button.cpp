#include "kp_standard_button.hpp"
#include <functional>

Standard_Button::Standard_Button(float p_x, float p_y, float s_x, float s_y, std::string txt, std::function<void()> f)
    :Button(p_x, p_y, s_x, s_y)
{
    label=txt;
    fv=f;
}

void Standard_Button::handle(event ev)
{
    if(focused && ev.keycode==key_enter)
    {
        fv();
    }
    if(contains(ev) && ev.button==btn_left)
    {
        fv();
    }
}

void Standard_Button::print() const
{
    canvas btn;
    btn.open(size_x, size_y);
    btn << move_to(0, 0) << color(0, 0, 0) << box(size_x, size_y)
        << move_to(1, 1) << color(100, 100, 100) << box(size_x-2, size_y-2)
        << move_to(size_x/2-gout.twidth(label)/2, size_y/2+gout.cascent()/2) << color(0, 0, 0) << text(label);
    gout << stamp(btn, pos_x, pos_y);
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
