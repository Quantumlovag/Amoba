#include "kp_tictac_button.hpp"
#include <vector>
#include "graphics.hpp"

using namespace genv;

TicTac_Button::TicTac_Button(float p_x, float p_y, float s_x, float s_y, std::function<void()> f)
    :Button(p_x, p_y, s_x, s_y)
{
    end_game=f;
    win_cond=0;
    turn=false;
    for(int i=0; i<40; i++)
    {
        std::vector<int> row;
        for(int j=0; j<40; j++)
        {
            row.push_back(0);
        }
        table.push_back(row);
        row.clear();
    }
}

void TicTac_Button::handle(event ev)
{
    for(size_t i=0; i<table.size(); i++)
    {
        for(size_t j=0; j<table[i].size(); j++)
        {
            if(ev.pos_x>i*20 && ev.pos_x<(i+1)*20 && ev.pos_y>j*20 && ev.pos_y<(j+1)*20 && ev.button==btn_left)
            {
                if(!turn && table[i][j]==0) table[i][j]=1, turn=!turn;
                if(turn && table[i][j]==0) table[i][j]=2, turn=!turn;
            }
        }
    }
    bool p1=false;
    bool p2=false;
    bool draw=true;
    int carry=0;
    int p1t=0;
    int p2t=0;
    for(size_t i=0; i<table.size(); i++)
    {
        for(size_t j=0; j<table[i].size(); j++)
        {
            if(!p1 && !p2)
            {
                if(carry==0) p1t=0, p2t=0;
                if(carry==1) p2t=0;
                if(carry==2) p1t=0;
                if(table[i][j]==1) p1t++, carry=1;
                if(table[i][j]==2) p2t++, carry=2;
                if(table[i][j]==0) draw=false;
            }
            if(p1t==5) p1=true;
            if(p2t==5) p2=true;
        }
        carry=0;
    }
    for(size_t i=0; i<table[0].size(); i++)
    {
        for(size_t j=0; j<table.size(); j++)
        {
            if(!p1 && !p2)
            {
                if(carry==0) p1t=0, p2t=0;
                if(carry==1) p2t=0;
                if(carry==2) p1t=0;
                if(table[j][i]==1) p1t++, carry=1;
                if(table[j][i]==2) p2t++, carry=2;
                if(table[j][i]==0) draw=false;
            }
            if(p1t==5) p1=true;
            if(p2t==5) p2=true;
        }
        carry=0;
    }
    if(p1) win_cond=1;
    if(p2) win_cond=2;
    if(draw) win_cond=3;
    end_game();
}

void TicTac_Button::print() const
{
    canvas tt_btn;
    tt_btn.open(size_x, size_y);
    for(size_t i=0; i<table.size(); i++)
    {
        for(size_t j=0; j<table[i].size(); j++)
        {
            tt_btn << move_to(i*20, j*20) << color(0, 0, 0) << box(20, 20)
                   << move_to(i*20+1, j*20+1) << color(255, 255, 255) << box(18, 18);
            if(table[i][j]==1)
            {
                tt_btn << move_to(i*20+3, j*20+3) << color(255, 0, 0) << box(14, 14);
            }
            if(table[i][j]==2)
            {
                tt_btn << move_to(i*20+3, j*20+3) << color(0, 0, 255) << box(14, 14);
            }
        }
    }
    gout << stamp(tt_btn, 0, 0);
}
