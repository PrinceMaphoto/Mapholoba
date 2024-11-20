#include "Cabbage.h"
#include "Plot.h"

Cabbage::Cabbage(Plot* plot) 
    : MediumPlant('C', plot) {}

Cabbage::~Cabbage()
{
    //virtual function
    //no dynamic memory
}

void Cabbage::water()
{
    if(!getPlanted())
    {
        return;
    }

    getWaterLevel()++;

    Plant** neighbours = getNeighbours();

    for(int i = 0; i < 8; i++)
    {
        if (neighbours[i] != NULL) 
        {
            neighbours[i]->getWaterLevel()++;
        }
    }

    delete [] neighbours;
}

void Cabbage::harvest()
{
    if(!getPlanted() || getWaterLevel() < 8)
    {
        return;
    }

    int numHarvest = 4;

    Plant** neighbours = getNeighbours();

    for(int i = 0; i < 8; i++)
    {
        if(neighbours[i] != NULL)
        {
            neighbours[i]->getWaterLevel()++;
        }
    }

    getPlanted() = false; 
    getWaterLevel() = 0;

    *plot->getPosition(y[0], x[0]) = -1;
    *plot->getPosition(y[0], x[1]) = -1;
    *plot->getPosition(y[1], x[0]) = -1;
    *plot->getPosition(y[1], x[1]) = -1;


    std::cout << "Harvested " << numHarvest << " Cabbages" << std::endl;
}