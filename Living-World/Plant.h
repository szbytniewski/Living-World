#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(int power, int health, Position position, int birthTurn);
	Plant();

	void move(int dx, int dy) override;
};