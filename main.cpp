#include "graphics.hpp"
#include "kp_window.hpp"
#include "kp_widgets.hpp"
#include "kp_standard_button.hpp"
#include "kp_tictac_button.hpp"
#include "kp_static_text.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace genv;

const int W=800;
const int H=800;

class GameTable : public Window
{
protected:
    TicTac_Button *ttb1;
public:
    GameTable(int inX, int inY);
    void end_game();
};

class MainMenu : public Window
{
protected:
    Standard_Button *sb1;
    Standard_Button *sb2;
public:
    MainMenu(int inX, int inY);
};

class EndMenu : public Window
{
protected:
    Static_Text *st1;
    Standard_Button *sb1;
public:
    EndMenu(int inX, int inY, int wc);
};

GameTable::GameTable(int inX, int inY)
    :Window(inX, inY)
{
    ttb1=new TicTac_Button(0, 0, W, H, [&]()
                           {
                               if(ttb1->get_win_cond()!=0)
                               {
                                   this->shutdown();
                                   EndMenu em(300, 300, ttb1->get_win_cond());
                                   em.events();
                               }
                           });
    add(ttb1);
}

EndMenu::EndMenu(int inX, int inY, int wc)
    :Window(inX, inY)
{
    string l;
    if(wc==1) l="Player 1 won!";
    if(wc==2) l="Player 2 won!";
    if(wc==3) l="Draw!";
    st1=new Static_Text(50, 100, 200, 30, l);
    sb1=new Standard_Button(100, 200, 100, 30, "Ok", [&]()
                            {
                               this->shutdown();
                               MainMenu mn(300, 300);
                               mn.events();
                            });
    add(st1), add(sb1);
}

MainMenu::MainMenu(int inX, int inY)
    :Window(inX, inY)
{
    sb1=new Standard_Button(100, 100, 100, 30, "Play", [&]()
                            {
                                this->shutdown();
                                GameTable gt(W, H);
                                gt.events();
                            });
    sb2=new Standard_Button(100, 200, 100, 30, "Exit", [&]()
                            {
                                this->shutdown();
                            });
    add(sb1), add(sb2);
}

int main()
{
    MainMenu mm(300, 300);
    mm.events();
    return 0;
}
