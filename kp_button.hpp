#ifndef KP_BUTTON_HPP_INCLUDED
#define KP_BUTTON_HPP_INCLUDED
#include "kp_widgets.hpp"

class Button : public Widgets
{
public:
    Button(float p_x, float p_y, float s_x, float s_y);
    virtual void print() const=0;
    virtual void handle(event ev) =0;
    virtual bool focusable() =0;
};


#endif // KP_BUTTON_HPP_INCLUDED
