#ifndef KP_TICTAC_BUTTON_HPP_INCLUDED
#define KP_TICTAC_BUTTON_HPP_INCLUDED
#include "kp_button.hpp"
#include <vector>

class TicTac_Button : public Button
{
protected:
    std::vector< std::vector<int> > table;
    bool turn;
public:
    TicTac_Button(float p_x, float p_y, float s_x, float s_y);
    virtual void print() const;
    virtual void handle(event ev);
    bool focusable() {return true;}
};


#endif // KP_TICTAC_BUTTON_HPP_INCLUDED
