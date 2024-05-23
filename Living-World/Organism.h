#pragma once
#include <string>
#include <vector>
#include "Position.h"

using namespace std;

struct AncestorInfo {
	int id;
	int birthTurn;
	int deathTurn; // Use -1 to indicate the ancestor is still alive


	AncestorInfo(int id, int birthTurn, int deathTurn)
		: id(id), birthTurn(birthTurn), deathTurn(deathTurn) {}
};

class Organism
{
private:
	static int nextId; // Static member for generating unique IDs
	int id;
	int power;
	int health;
	int maxHealth;
	Position position;
	string species;
	int birthTurn;
	vector<AncestorInfo> ancestors;

public:
	
	Organism(int power, int health, Position position, int birthTurn); //values that you have to put when creating an object
	virtual ~Organism() = default; // Virtual destructor

	int getId() const;

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

	void addAncestor(int id, int birthTurn);
	void updateAncestorDeathTurn(int ancestorId, int deathTurn);
	void propagateAncestorDeathTurn(int ancestorId, int deathTurn);
	void regenerateHealth();
	virtual bool canReproduce() const = 0;
	virtual Organism* createChild(int birthTurn) const = 0;

	virtual bool canAttack() const = 0;
	virtual void attack(Organism& target) = 0; 


	string toString();

	virtual void move(int dx, int dy);
};