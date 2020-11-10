#include <Data.hpp>
using namespace watersim;

bool Data::cellOn(int x, int y) {
    if (x < 0 || y < 0 || x > static_cast<int>(cells.size()-1) || y > static_cast<int>(cells.size()-1)) {
        return false; // out of bounds
    } else {
        return cells[x][y].on;
    }
}

bool Data::cellOn(const std::pair<int,int> &coords) {
    return cellOn(coords.first, coords.second);
}