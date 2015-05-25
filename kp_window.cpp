#include "kp_window.hpp"
#include "graphics.hpp"

using namespace genv;

Window::Window(int inX, int inY)
{
    X=inX, Y=inY;
    gout.open(X, Y);
    exit=false;
}

void Window::events()
{
    event ev;
    int focus=-1;
    while(gin>>ev && !exit)
    {
        if(ev.type==ev_key && ev.keycode==key_tab)
        {
            if(focus!=-1)
            {
                v_widgets[focus]->unfocus();
            }
            do
            {
                focus++;
                if(focus>=v_widgets.size())
                {
                    focus=0;
                }
            }
            while(!v_widgets[focus]->focusable());
            v_widgets[focus]->focus();
        }
        if(ev.type==ev_mouse && ev.button==btn_left)
        {
            for(size_t i=0; i<v_widgets.size(); i++)
            {
                if(v_widgets[i]->contains(ev) && v_widgets[i]->focusable())
                {
                    if(focus!=-1)
                    {
                        v_widgets[focus]->unfocus();
                    }
                    focus=i;
                    v_widgets[focus]->focus();
                }
            }
        }
        if (focus!=-1)
        {
            v_widgets[focus]->handle(ev);
        }
        gout << move_to(0, 0) << color(155, 155, 155) << box(X, Y);
        for(size_t i=0; i<v_widgets.size(); i++)
        {
            v_widgets[i]->print();
        }
        gout << refresh;
    }
}

void Window::shutdown()
{
    exit=true;
}

void Window::add(Widgets *w)
{
    v_widgets.push_back(w);
}
