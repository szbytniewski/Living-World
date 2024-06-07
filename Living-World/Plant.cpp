#include "Plant.h"

Plant::Plant(int power, int health, int maxHealth, Position position, int birthTurn, string species) 
	: Organism(power, health, maxHealth, position, birthTurn, species)
{
}

void Plant::move(int dx, int dy) {
	// Plants do not move
}