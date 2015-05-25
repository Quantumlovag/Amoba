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

class MyApp : public Window
{
protected:
    TicTac_Button *ttb1;
public:
    MyApp(int inX, int inY);
};

MyApp::MyApp(int inX, int inY)
    :Window(inX, inY)
{
    ttb1=new TicTac_Button(0, 0, W, H);
    add(ttb1);
}

int main()
{
    cout << "Hello World!";
    MyApp app(W, H);
    app.events();
    return 0;
}
