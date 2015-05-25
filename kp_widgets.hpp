#ifndef KP_WIDGETS_HPP_INCLUDED
#define KP_WIDGETS_HPP_INCLUDED
#include "graphics.hpp"

using namespace genv;

class Widgets
{
protected:
    float pos_x, pos_y;
    float size_x, size_y;
    bool focused;
public:
    Widgets(float p_x, float p_y, float s_x, float s_y);
    virtual void print() const=0;
    virtual void handle(event ev) =0;
    virtual bool focusable() =0;
    void focus();
    void unfocus();
    bool contains(event ev);
};

#endif // KP_WIDGETS_HPP_INCLUDED
