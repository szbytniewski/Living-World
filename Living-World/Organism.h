#pragma once
#include <string>
#include "Position.h"

using namespace std;

class Organism
{
private:
	int power;
	int health;
	int maxHealth;
	Position position;
	string species;
public:
	
	Organism(int power, int health, Position position); //values that you have to put when creating an object
	Organism() : power(0), health(0), maxHealth(0), position(0, 0), species("O") {}; //default values

	int getPower();
	void setPower(int power);
	int getHealth();
	void setHealth(int health);
	int getMaxHealth();
	void setMaxHealth(int maxHealth);
	Position getPosition();
	void setPosition(Position position);
	string getSpecies();
	void setSpecies(string spec);

	string toString();

	virtual void move(int dx, int dy);
};