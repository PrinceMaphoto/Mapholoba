#include "Radish.h"
#include "Plot.h"
#include <cmath>

Radish::Radish(Plot* plot, int period)
    : SmallPlant('r', plot)
{
    if(period == 0)
    {
        this->period = 10;
    }

    this->period = std::abs(period);
}

Radish::~Radish()
{
    //Virtual destructor 
    //No dynamic memory to release
}

void Radish::water()
{
    if(!getPlanted())
    {
        return;
    }

    getWaterLevel()++;
}

void Radish::harvest()
{
    if(!getPlanted() || getWaterLevel() < 8)
    {
        return;
    }

    int sum = 0;
    Plant** neighbours = getNeighbours();

    for(int i = 0; i < 4; i++)
    {
        if(neighbours[i] != NULL)
        {
            //null check
            sum += neighbours[i]->getWaterLevel();
        }
    }

    //double pi = acos(0) * 2;
    double angle = (getWaterLevel() * 2 * M_PI) / period;
    double numHarvest = sum * std::pow(std::sin(angle), 2);

    int numRadishes = static_cast<int>(std::floor(numHarvest));

    *plot->getPosition(y, x) = -1;

    getPlanted() = false;
    getWaterLevel() = 0;

    std::cout << "Harvested " << sum << " radishes" << std::endl;
}