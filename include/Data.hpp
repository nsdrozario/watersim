#ifndef WATERSIM_DATA_HPP
#define WATERSIM_DATA_HPP

#include <watersim.hpp>
#include <Cell.hpp>

namespace watersim {
    struct Data {
        static std::vector<std::vector<Cell>> cells;
        static bool cellOn(int x, int y);
        static bool cellOn(const std::pair<int,int> &coords);
    };
}

#endif