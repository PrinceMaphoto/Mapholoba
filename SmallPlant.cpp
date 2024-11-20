#include "SmallPlant.h"
#include "Plot.h"
#include <iostream>

SmallPlant::SmallPlant(char icon, Plot* plot) : Plant(icon, plot), x(-1), y(-1) {}

SmallPlant::~SmallPlant() {
    // No dynamic memory to clean up
}

bool SmallPlant::plantSeed() {
    if (getPlanted()) {
        return false;
    }

    int rows = plot->getNumRows();
    int cols = plot->getNumCols();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*plot->getPosition(i, j) == -1) {
                *plot->getPosition(i, j) = plot->addPlant(this);
                x = j;
                y = i;
                getPlanted() = true;
                return true;
            }
        }
    }
    return false;
}

Plant** SmallPlant::getNeighbours() {
    Plant** neighbours = new Plant*[4];

    for (int i = 0; i < 4; i++) {
        neighbours[i] = NULL;
    }

    int rows = plot->getNumRows();
    int cols = plot->getNumCols();

    if (x - 1 >= 0) {
        neighbours[0] = plot->getPlant(plot->getPosition(y, x - 1));
    }

    if (y - 1 >= 0) {
        neighbours[1] = plot->getPlant(plot->getPosition(y - 1, x));
    }

    if (x + 1 < cols) {
        neighbours[2] = plot->getPlant(plot->getPosition(y, x + 1));
    }

    if (y + 1 < rows) {
        neighbours[3] = plot->getPlant(plot->getPosition(y + 1, x));
    }

    return neighbours;
}
