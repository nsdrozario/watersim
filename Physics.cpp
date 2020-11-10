#include <Physics.hpp>
#include <Cell.hpp>
#include <Data.hpp>

using namespace watersim;

void Physics::simulateFrame() {

    int i, j = 0;
    bool **visited;
    
    try {
        visited = new bool *[Data::cells.size()];
        for (int k = 0; k < Data::cells.size(); k++) {
            visited[k] = new bool[Data::cells[0].size()];
        }
    } catch (std::bad_alloc e) {
        std::cerr << "memory allocation failure for physics simulation" << std::endl;
        for (int k = 0; k < Data::cells.size(); k++) {
            delete visited[k];
        }
        delete visited;
        return;
    }

    for (std::vector<Cell> v : Data::cells) {
        for (Cell c : v) {
            if (!c.on || visited[i][j]) {
                j++;
                continue;
            }

            if (Data::cellOn(i, j+1) && Data::cellOn(i, j+2)) { // is cell completely blocked
                
                int x = i;

                if (Data::cellOn(i+1, j)) {
                    while (!Data::cellOn(x, j) && x < Data::cells.size() && abs(x-i) <= SPREAD_VELOCITY) {
                        x++;
                    }
                    Data::cells[x][j] = Cell(Data::cells[i][j]);
                    Data::cells[i][j] = Cell();
                } else if (Data::cellOn(i-1, j)) {
                    while (!Data::cellOn(x, j) && x < Data::cells.size() && abs(x-i) <= SPREAD_VELOCITY) {
                        x--;
                    }
                    Data::cells[x][j] = Cell(Data::cells[i][j]);
                    Data::cells[i][j] = Cell();
                }

            } else {

                c.velocity += Physics::g;
                int y = j;
                while (!Data::cellOn(i, y) && y-j <= c.velocity && y < v.size()) {
                    y++;
                }

                Data::cells[i][y] = Cell(Data::cells[i][j]);
                Data::cells[i][j] = Cell();

            }

            j++;
        }
        i++;
    }

    // deallocate memory before exiting
    for (int k = 0; k < Data::cells.size(); k++) {
            delete visited[k];
        }
    delete visited;

}