#include "Animal.h"

Animal::Animal(int power, int health, Position position, int birthTurn) : Organism(power, health, position, birthTurn)
{
	setMaxHealth(10);
	setSpecies("A");
}

Animal::Animal() : Organism()
{
	setMaxHealth(0);
	setSpecies("A");
}