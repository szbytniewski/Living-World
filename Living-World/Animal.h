#pragma once
#include "Organism.h"

using namespace std;

class Animal : public Organism
{
public:
	Animal(int power, int health, int maxHealth, Position position, int birthTurn, string species);
	
	virtual ~Animal() = default;
};