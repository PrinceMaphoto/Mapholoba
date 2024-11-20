#include "Plant.h"

Plant::Plant(char icon, Plot* plot) 
    : waterLevel(0), icon(icon), planted(false), plot(plot) {}

Plant::~Plant()
{
    // No dynamic memory to clean because plot is a shallow copy
}

char Plant::getIcon() 
{
    return icon;
}

int& Plant::getWaterLevel()
{
    return waterLevel;
}

bool& Plant::getPlanted()
{
    return planted;
}