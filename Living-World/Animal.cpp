#include "Animal.h"

Animal::Animal(int power, int health, int maxHealth, Position position, int birthTurn, string species) : Organism(power, health, maxHealth, position, birthTurn, species)
{
	setMaxHealth(10);
	setSpecies("A");
}

