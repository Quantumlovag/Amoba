#include "kp_choice_window.hpp"
#include "graphics.hpp"
#include <vector>
#include <string>

using namespace genv;

Choice_Window::Choice_Window(float x, float y, float sx, float sy, int o_s, std::vector<std::string> v_c)
    :Widgets(x, y, sx, sy)
{
    position=0;
    open_size=o_s;
    for(size_t i=0; i<v_c.size(); i++)
    {
        choices.push_back(v_c[i]);
    }
    chosen=choices.size()-1;
}

void Choice_Window::print() const
{
    canvas cwin;
    cwin.open(size_x, size_y);
    cwin << move_to(0, 0) << color(0, 0, 0) << box(size_x, size_y)
         << move_to(1, 1) << color(255, 255, 255) << box(size_x-2, size_y-2)
         << move_to(size_x-20, 0) << color(0, 0, 0) << box(20, size_y)
         << move_to(size_x-20, 0) << color(255, 255, 255) << line_to(size_x-10, size_y-1)
         << move_to(size_x-10, size_y-1) << color(255, 255, 255) << line_to(size_x, 0);
    if(choices.size()==0)
    {
        cwin << move_to(10, size_y/2+gout.cascent()/2) << color(0, 0, 0) << text("");
    }
    else
    {
        cwin << move_to(10, size_y/2+gout.cascent()/2) << color(0, 0, 0) << text(choices[chosen]);
    }
    if(focused)
    {
        gout << move_to(pos_x, pos_y+size_y) << color(0, 0, 0) << box(size_x, open_size*30)
             << move_to(pos_x+1, pos_y+size_y+1) << color(255, 255, 255) << box(size_x-2, open_size*30-2);
        for(int i=position; ((i<open_size+position && choices.size()>=open_size+position) || (i<choices.size() && choices.size()<open_size+position)); i++)
        {
            if(i==chosen)
            {
                gout << move_to(pos_x+1, pos_y+size_y+(i-position)*30+1) << color(0, 0, 255) << box(size_x-2, 28)
                     << move_to(pos_x+10, pos_y+size_y+15+gout.cascent()/2+(i-position)*30) << color(255, 255, 255) << text(choices[i]);
            }
            else
            {
                gout << move_to(pos_x+10, pos_y+size_y+15+gout.cascent()/2+(i-position)*30) << color(0, 0, 0) << text(choices[i]);
            }
        }
    }
    gout << stamp(cwin, pos_x, pos_y);
}

void Choice_Window::handle(event ev)
{
    if(ev.button==btn_left && ((ev.pos_x<pos_x || ev.pos_x>pos_x+size_x) || (ev.pos_y<pos_y || ev.pos_y>pos_y+size_y+open_size*30))) focused=false;
    if(contains(ev) && ev.button==btn_left)
    {
        focused=true;
    }
    if(focused)
    {
        for(int i=position; ((i<open_size+position && choices.size()>=open_size+position) || (i<choices.size() && choices.size()<open_size+position)); i++)
        {
            if(ev.button==btn_left && ev.pos_x>=pos_x && ev.pos_x<=pos_x+size_x && ev.pos_y>=pos_y+size_y+(i-position)*30 && ev.pos_y<=pos_y+size_y+(i-position+1)*30)
            {
                chosen=i;
            }
        }
        if(ev.button==btn_wheelup && position>0)
        {
            position--;
        }
        if(ev.button==btn_wheeldown && position<choices.size()-open_size)
        {
            position++;
        }
    }
}

void Choice_Window::add_choice(std::string choice)
{
    choices.push_back(choice);
}

void Choice_Window::delete_choice()
{
    std::vector<std::string> temp;
    temp=choices;
    choices.clear();
    for(size_t i=0; i<temp.size(); i++)
    {
        if(i!=chosen)
        {
            choices.push_back(temp[i]);
        }
    }
}

std::string Choice_Window::get_chosen()
{
    return choices[chosen];
}
