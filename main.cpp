#include "graphics.hpp"
#include "kp_window.hpp"
#include "kp_widgets.hpp"
#include "kp_standard_button.hpp"
#include "kp_tictac_button.hpp"
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
};

GameTable::GameTable(int inX, int inY)
    :Window(inX, inY)
{
    ttb1=new TicTac_Button(0, 0, W, H);
    add(ttb1);
}

class MainMenu : public Window
{
protected:
    Standard_Button *sb1;
    Standard_Button *sb2;
public:
    MainMenu(int inX, int inY);
};

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
