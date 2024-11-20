#include "MediumPlant.h"
#include "Plot.h"
#include <iostream>

MediumPlant::MediumPlant(char icon, Plot* plot) : Plant(icon, plot) {
    x[0] = -1;
    x[1] = -1;
    y[0] = -1;
    y[1] = -1;
}

MediumPlant::~MediumPlant() {
    // No dynamic memory to clean
}

bool MediumPlant::plantSeed() {
    if (getPlanted()) {
        return false;
    }

    int rows = plot->getNumRows();
    int cols = plot->getNumCols();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i + 1 < rows && j + 1 < cols &&
                *plot->getPosition(i, j) == -1 &&
                *plot->getPosition(i, j + 1) == -1 &&
                *plot->getPosition(i + 1, j) == -1 &&
                *plot->getPosition(i + 1, j + 1) == -1) {

                int plantIndex = plot->addPlant(this);
                *plot->getPosition(i, j) = plantIndex;
                *plot->getPosition(i, j + 1) = plantIndex;
                *plot->getPosition(i + 1, j) = plantIndex;
                *plot->getPosition(i + 1, j + 1) = plantIndex;

                x[0] = j;
                y[0] = i;
                x[1] = j + 1;
                y[1] = i + 1;

                getPlanted() = true;
                return true;
            }
        }
    }
    return false;
}

Plant** MediumPlant::getNeighbours() {
    Plant** neighbours = new Plant*[8];
    for (int i = 0; i < 8; i++) {
        neighbours[i] = NULL;
    }

    int rows = plot->getNumRows();
    int cols = plot->getNumCols();

    int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

    for (int i = 0; i < 8; i++) {
        int nx = x[0] + dx[i];
        int ny = y[0] + dy[i];

        if (nx >= 0 && ny >= 0 && nx < cols && ny < rows) {
            neighbours[i] = plot->getPlant(plot->getPosition(ny, nx));
        }
    }

    return neighbours;
}
