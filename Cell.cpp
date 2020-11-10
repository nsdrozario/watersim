#include <Cell.hpp>
using namespace watersim;

Cell::Cell () {
    this->on = false;
    this->velocity = 0;
    body.setFillColor(sf::Color::Cyan);
    body.setSize(sf::Vector2f(CELL_SIZE_PX, CELL_SIZE_PX));
}
Cell::Cell(const sf::Vector2f &f) {
    this->on = false;
    this->velocity = 0;
    body.setFillColor(sf::Color::Cyan);
    body.setSize(f);
}
void Cell::draw() const {
    if (this->on)
        UI::renderWindow.draw(this->body);
}