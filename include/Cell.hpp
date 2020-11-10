#ifndef WATERSIM_CELL_HPP
#define WATERSIM_CELL_HPP

#include "watersim.hpp"
#include "UI.hpp"

namespace watersim {
    struct Cell {
            sf::RectangleShape body;
            bool on = false;
            int velocity = 0;

            Cell();
            Cell(const sf::Vector2f &f);
            Cell(int x, int y) : Cell(sf::Vector2f(x,y)) { }
            Cell(float x, float y) : Cell(sf::Vector2f(x,y)) { }
            
            void draw() const;
            /*
          
            */
        };
}
#endif