#pragma once
#include <string>
#include <vector>
#include "Position.h"

using namespace std;

struct AncestorInfo {
	int birthTurn;
	int deathTurn; // Use -1 to indicate the ancestor is still alive
	string species;

	AncestorInfo(int birthTurn, int deathTurn, string species)
		: birthTurn(birthTurn), deathTurn(deathTurn), species(species) {}
};

class Organism
{
private:
	int power;
	int health;
	int maxHealth;
	Position position;
	string species;
	int birthTurn;
	vector<AncestorInfo> ancestors;

public:
	
	Organism(int power, int health, Position position, int birthTurn); //values that you have to put when creating an object
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
	int getBirthTurn();
	void setBirthTurn(int birthTurn);
	vector<AncestorInfo>& getAncestors();

	void addAncestor(int birthTurn, string species);
	void updateAncestorDeathTurn(string species, int deathTurn);
	void regenerateHealth();
	bool canReproduce();
	Organism createChild(int birthTurn);

	bool canAttack();
	void attack(Organism& target);


	string toString();

	virtual void move(int dx, int dy);
};