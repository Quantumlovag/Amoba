#ifndef CHOICE_WINDOW_HPP_INCLUDED
#define CHOICE_WINDOW_HPP_INCLUDED
#include "kp_widgets.hpp"
#include <vector>
#include <string>

class Choice_Window : public Widgets
{
protected:
    int open_size, position, chosen;
    std::vector<std::string> choices;
public:
    Choice_Window(float x, float y, float sx, float sy, int o_s, std::vector<std::string> v_c);
    void handle(event ev);
    void print() const;
    void add_choice(std::string choice);
    void delete_choice();
    std::string get_chosen();
};

#endif // CHOICE_WINDOW_HPP_INCLUDED

