#pragma once
#include "Organism.h"

using namespace std;

class Animal : public Organism
{
public:
	Animal(int power, int health, int maxHealth, Position position, int birthTurn, string species);
	
	virtual ~Animal() = default;

	bool canReproduce() const override = 0;
	Organism* createChild(int birthTurn) const override = 0; 

	bool canAttack() const override = 0;
	void attack(Organism& target) override = 0;


	void move(int dx, int dy) override;
};