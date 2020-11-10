#include <watersim.hpp>
#include <UI.hpp>
#include <Cell.hpp>
#include <Data.hpp>
#include <Physics.hpp>
using namespace watersim;

sf::RenderWindow UI::renderWindow;
bool UI::uses_bg_image = false;
std::vector<std::vector<Cell>> Data::cells;
int Physics::g = GRAVITY;
int Physics::spreadVelocity = SPREAD_VELOCITY;

std::ifstream config;
sf::Event e;

int main (int argc, char *argv[]) {

    // TODO: read config

    // init window
    UI::renderWindow.create(
        sf::VideoMode (
            CELL_SIZE_PX * GRID_WIDTH_CELLS,
            CELL_SIZE_PX * GRID_HEIGHT_CELLS
        ),
        "Water Simulation",
        sf::Style::Default
    );

    // initialize grid
    Data::cells.resize(GRID_WIDTH_CELLS);
    for (int i = 0; i < GRID_WIDTH_CELLS; i++) {
        Data::cells[i].resize(GRID_HEIGHT_CELLS);
        for (int j = 0 ; j < GRID_HEIGHT_CELLS; j++) {
            Data::cells[i][j] = Cell();
            Data::cells[i][j].body.setPosition(CELL_SIZE_PX * i, CELL_SIZE_PX * j);
        }
    }

    std::clog << "Initialization done" << std::endl;

    // draw loop
    while (UI::renderWindow.isOpen()) {
        while (UI::renderWindow.pollEvent(e)) {
            if (e.type == e.Closed) {
                if (config.is_open()) {
                    config.close();
                }
                return 0;
            }

            Physics::simulateFrame();

            UI::renderWindow.clear(sf::Color::Black);
            UI::drawMain();
            UI::renderWindow.display();
        }
    }

    return 0;

}