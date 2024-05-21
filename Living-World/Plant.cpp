#include "Plant.h"
#include <iostream>

Plant::Plant(int power, int health, Position position, int birthTurn) : Organism(power, health, position, birthTurn)
{
	setMaxHealth(health + 1);
	setSpecies("P");
}

Plant::Plant() : Organism()
{
	setMaxHealth(0);
	setSpecies("P");
}

void Plant::move(int dx, int dy)
{
	Organism::move(0, 0);
}