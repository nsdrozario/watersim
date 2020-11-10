#ifndef WATERSIM_UI_HPP
#define WATERSIM_UI_HPP

#include "watersim.hpp"

namespace watersim {
    struct UI {
        static sf::RenderWindow renderWindow;
        static bool uses_bg_image;
        static void drawMain();
    };
}

#endif