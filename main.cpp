#include "Plot.h"
#include "Carrot.h"
#include "Radish.h"
#include "Cabbage.h"
#include "Pineapple.h"

#include <iostream>

void testPlantingAndHarvesting() {
    std::cout << "=== Testing Planting and Harvesting ===" << std::endl;

    Plot plot(4, 4);  // 4x4 plot
    plot.printPlot();
    
    Carrot carrot(&plot, 2);
    Radish radish(&plot, 5);
    Cabbage cabbage(&plot);
    Pineapple pineapple(&plot);

    // Test planting
    std::cout << "Planting Carrot: " << (carrot.plantSeed() ? "Success" : "Failure") << std::endl;
    plot.printPlot();

    std::cout << "Planting Radish: " << (radish.plantSeed() ? "Success" : "Failure") << std::endl;
    plot.printPlot();

    std::cout << "Planting Cabbage: " << (cabbage.plantSeed() ? "Success" : "Failure") << std::endl;
    plot.printPlot();

    std::cout << "Planting Pineapple: " << (pineapple.plantSeed() ? "Success" : "Failure") << std::endl;
    plot.printPlot();

    // Test watering
    std::cout << "Watering all plants..." << std::endl;
    plot.waterAllPlants();
    plot.waterAllPlants(); // Water again to test repeated watering
    plot.printPlot();

    // Test harvesting
    std::cout << "Harvesting all plants..." << std::endl;
    plot.harvestAllPlants();
    plot.printPlot();
}

void testNeighbours() {
    std::cout << "=== Testing Neighbours Functionality ===" << std::endl;

    Plot plot(3, 3);  // 3x3 plot
    Carrot carrot1(&plot, 2);
    Carrot carrot2(&plot, 2);

    carrot1.plantSeed();  // Plant a carrot
    carrot2.plantSeed();  // Plant another carrot next to it

    plot.printPlot();

    // Get and print neighbours of the first carrot
    Plant** neighbours = carrot1.getNeighbours();
    std::cout << "Neighbours of Carrot 1: " << std::endl;
    for (int i = 0; i < 4; i++) {
        if (neighbours[i] != NULL) {
            std::cout << "Neighbour " << i << ": " << neighbours[i]->getIcon() << std::endl;
        } else {
            std::cout << "Neighbour " << i << ": NULL" << std::endl;
        }
    }

    delete [] neighbours; // Free the allocated memory
}

void testDynamicArrayResizing() {
    std::cout << "=== Testing Dynamic Array Resizing in Plot ===" << std::endl;

    Plot plot(2, 2);  // 2x2 plot, intentionally small to trigger resizing

    Carrot carrot1(&plot, 3);
    Carrot carrot2(&plot, 2);
    Carrot carrot3(&plot, 1);

    carrot1.plantSeed();
    carrot2.plantSeed();
    carrot3.plantSeed();

    plot.printPlot();  // Check if all plants are planted correctly
}

int main() {
    testPlantingAndHarvesting();
    testNeighbours();
    testDynamicArrayResizing();

    return 0;
}
