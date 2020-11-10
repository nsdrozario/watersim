#include <UI.hpp>
#include <Cell.hpp>
#include <Data.hpp>

using namespace watersim;

void UI::drawMain() {
    for (std::vector<Cell> v : Data::cells) {
        for (Cell c : v) {
            c.draw();
        }
    }
}
