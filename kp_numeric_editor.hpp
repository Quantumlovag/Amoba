#ifndef KP_NUMERIC_EDITOR_HPP_INCLUDED
#define KP_NUMERIC_EDITOR_HPP_INCLUDED
#include "kp_widgets.hpp"

class Numeric_Editor : public Widgets
{
protected:
    int number, minimum, maximum;
public:
    Numeric_Editor(float p_x, float p_y, float s_x, float s_y, int mini, int maxi);
    void print() const;
    void handle(event ev);
    bool focusable() {return true;}
};



#endif // KP_NUMERIC_EDITOR_HPP_INCLUDED
