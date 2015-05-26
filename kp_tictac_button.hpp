#ifndef KP_TICTAC_BUTTON_HPP_INCLUDED
#define KP_TICTAC_BUTTON_HPP_INCLUDED
#include "kp_button.hpp"
#include <vector>
#include <functional>

class TicTac_Button : public Button
{
protected:
    std::vector< std::vector<int> > table;
    bool turn;
    int win_cond;
    std::function<void()> end_game;
public:
    TicTac_Button(float p_x, float p_y, float s_x, float s_y, std::function<void()> f);
    virtual void print() const;
    virtual void handle(event ev);
    bool focusable() {return true;}
    int get_win_cond() {return win_cond;}
};


#endif // KP_TICTAC_BUTTON_HPP_INCLUDED
