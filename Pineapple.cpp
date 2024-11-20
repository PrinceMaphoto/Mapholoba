#include "Pineapple.h"
#include "Plot.h"

Pineapple::Pineapple(Plot* plot)
    : MediumPlant('P', plot), historySize(0), waterHistory(NULL) {}

Pineapple::~Pineapple()
{
    //virtual destructor 

    delete [] waterHistory;
}

void Pineapple::water()
{
    if(!getPlanted())
    {
        return;
    }

    getWaterLevel()++;

    Plant** neighbours = getNeighbours();
    int sum = 0;

    for(int i = 0; i < 8; i++)
    {
        if(neighbours[i] != NULL)
        {
            int neighbourWater = neighbours[i]->getWaterLevel();
            sum += neighbourWater;
        }
    }

    int * newHistory = new int[historySize + 1];

    for(int i = 0; i < historySize; i++)
    {
        newHistory[i] = waterHistory[i];
    }

    newHistory[historySize] = sum;
    historySize++;

    delete [] waterHistory;
    waterHistory = newHistory;

    delete [] neighbours;
}

void Pineapple::harvest()
{
    if(!getPlanted() || getWaterLevel() < 8)
    {
        return;
    }

    int sum = 0;

    for(int i = 0; i < historySize; i++)
    {
        sum += waterHistory[i];
    }

    int numHarvest = 1 + (sum/4);
    
    Plant** neighbours = getNeighbours();

    for(int i = 0; i < 8; i++)
    {
        if(neighbours[i] != NULL)
        {
            neighbours[i]->getWaterLevel()++;
        }
    }

    delete [] waterHistory;
    waterHistory = NULL;

    historySize = 0; 
    getWaterLevel() = 0;
    getPlanted() = false;

    *plot->getPosition(y[0], x[0]) = -1;
    *plot->getPosition(y[0], x[1]) = -1;
    *plot->getPosition(y[1], x[0]) = -1;
    *plot->getPosition(y[1], x[1]) = -1;

    std::cout << "Harvested " << numHarvest << " Pineapples" << std::endl;
}