#include "Carrot.h"
#include "Plot.h"

Carrot::Carrot(Plot* plot, int harvestCycle) 
    : SmallPlant('c', plot), numLeaves(0)
{
    if(harvestCycle <= 0 )
    {
        this->harvestCycle = 1;
    }
    else
    {
        this->harvestCycle = harvestCycle;
    }
}

Carrot::~Carrot()
{
    // No dynamic memory to clean up
}

void Carrot::water()
{
    if(!getPlanted())
    {
        return;
    }

    getWaterLevel()++;
    numLeaves++;

    // Ensure numLeaves stays within the range of harvestCycle
    numLeaves %= harvestCycle;
}

void Carrot::harvest()
{
    // Check if the carrot is planted and has sufficient water for harvesting
    if(!getPlanted() || getWaterLevel() < 8)
    {
        return;
    }

    int numHarvest = numLeaves;  

    *plot->getPosition(y, x) = -1; 

    // Reset plant status after harvest
    getPlanted() = false;
    getWaterLevel() = 0;

    std::cout << "Harvested " << numHarvest << " carrots" << std::endl;
}

