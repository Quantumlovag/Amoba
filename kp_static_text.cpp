#include "kp_static_text.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;

Static_Text::Static_Text(float p_x, float p_y, float s_x, float s_y, std::string l)
    : Widgets(p_x, p_y, s_x, s_y)
{
    label=l;
}

void Static_Text::print() const
{
    canvas stext;
    stext.open(size_x, size_y);
    stext << move_to(0, 0) << color(0, 0, 0) << box(size_x, size_y)
          << move_to(1, 1) << color(255, 255, 255) << box(size_x-2, size_y-2)
          << move_to(5, size_y/2+gout.cascent()/2) << color(0, 0, 0) << text(label);
    gout << stamp(stext, pos_x, pos_y);
}
