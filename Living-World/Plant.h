#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(int power, int health, int maxHealth, Position position, int birthTurn, string species);


	virtual ~Plant() = default;
};