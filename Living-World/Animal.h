#pragma once
#include "Organism.h"

using namespace std;

class Animal : public Organism
{
public:
	Animal(int power, int health, Position position);
	Animal();

};