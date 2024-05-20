#include "Animal.h"

Animal::Animal(int power, int health, Position position) : Organism(power, health, position)
{
	setMaxHealth(health + 3);
	setSpecies("A");
}

Animal::Animal() : Organism()
{
	setMaxHealth(0);
	setSpecies("A");
}