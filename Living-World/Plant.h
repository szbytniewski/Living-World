#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(int power, int health, int maxHealth, Position position, int birthTurn, string species);


	virtual ~Plant() = default;

	bool canReproduce() const override = 0; 
	Organism* createChild(int birthTurn) const override = 0;
	virtual bool canAttack() const override = 0;
	virtual void attack(Organism& target) override = 0;

	void move(int dx, int dy) override {
		// Plants do not move
	}
};