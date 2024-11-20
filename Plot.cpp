#include "Plot.h"
#include "Plant.h"  // Added to resolve incomplete type error
#include <iostream>

Plot::Plot(int numRows, int numCols) : numRows(numRows), numCols(numCols), numPlants(0) {
    soil = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        soil[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            soil[i][j] = -1;  // -1 indicates no plant is present
        }
    }
    plants = NULL;
}

Plot::~Plot() {
    for (int i = 0; i < numRows; i++) {
        delete[] soil[i];
    }
    delete[] soil;

    for (int k = 0; k < numPlants; k++) {
        delete plants[k];  // Delete each plant
    }
    delete[] plants;  // Delete the plant array
}

void Plot::waterAllPlants() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (soil[i][j] != -1) {
                if (soil[i][j] < numPlants) {  // Bounds check
                    plants[soil[i][j]]->water();  // No more "incomplete type" error
                }
            }
        }
    }
}

void Plot::harvestAllPlants() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (soil[i][j] != -1) {
                if (soil[i][j] < numPlants) {  // Bounds check
                    plants[soil[i][j]]->harvest();  // No more "incomplete type" error
                }
            }
        }
    }
}

void Plot::printPlot() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (soil[i][j] != -1) {
                if (soil[i][j] < numPlants) {  // Bounds check
                    std::cout << plants[soil[i][j]]->getIcon();  // No more "incomplete type" error
                } else {
                    std::cout << "-";
                }
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}

int Plot::getNumRows() {
    return numRows;
}

int Plot::getNumCols() {
    return numCols;
}

int* Plot::getPosition(int row, int col) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        return NULL;  // Out of bounds, return NULL
    }
    return &soil[row][col];
}

Plant* Plot::getPlant(int* idx) {
    if (idx == NULL || *idx < 0 || *idx >= numPlants) {
        return NULL;  // Invalid index or out of bounds
    }
    return plants[*idx];
}

int Plot::addPlant(Plant* plant) {
    Plant** newPlants = new Plant*[numPlants + 1];

    for (int i = 0; i < numPlants; i++) {
        newPlants[i] = plants[i];
    }

    newPlants[numPlants] = plant;
    delete[] plants;

    plants = newPlants;

    return numPlants++;  // Return the index of the added plant
}
