#pragma once
#include "Animal.h"
#include "Plant.h"

class Sheep : public Animal
{
public:
	Sheep(Position position, int birthTurn)
		: Animal(3, 3, 8, position, birthTurn, "S") {}

	bool canReproduce() const override {
		return getHealth() == getMaxHealth();
	}
};

