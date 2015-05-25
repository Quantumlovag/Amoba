#include "kp_text_editor.hpp"
#include <string>

using namespace genv;

Text_Editor::Text_Editor(float p_x, float p_y, float s_x, float s_y, std::string s)
    : Widgets(p_x, p_y, s_x, s_y)
{
    txt=s;
}

void Text_Editor::print() const
{
    canvas dtext;
    std::string out_txt=txt;
    dtext.open(size_x, size_y);
    dtext << move_to(0, 0) << color(0, 0, 0) << box(size_x, size_y)
          << move_to(1, 1) << color(255, 255, 255) << box(size_x-2, size_y-2);
    while(dtext.twidth(out_txt)>size_x-12)
    {
        out_txt=out_txt.substr(1, out_txt.size()-1);
    }
    dtext << move_to(6, size_y-6) << color(0, 0, 0) << text(out_txt);
    if(focused)
    {
        dtext << text("|");
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
    gout << stamp(dtext, pos_x, pos_y);
}

void Text_Editor::handle(event ev)
{
    if(ev.type == ev_key)
    {
        if(ev.keycode>=' ' && ev.keycode<255)
        {
            txt+=ev.keycode;
        }
        if(ev.keycode == key_backspace)
        {
            txt=txt.substr(0,txt.length()-1);
        }
    }
}
