#ifndef KP_TEXT_EDITOR_HPP_INCLUDED
#define KP_TEXT_EDITOR_HPP_INCLUDED
#include "kp_widgets.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;

class Text_Editor : public Widgets
{
protected:
    std::string txt;
public:
    Text_Editor(float p_x, float p_y, float s_x, float s_y, std::string s);
    void print() const;
    void handle(event ev);
    bool focusable() {return true;};
    std::string get_txt() {return txt;}
};


#endif // KP_TEXT_EDITOR_HPP_INCLUDED
