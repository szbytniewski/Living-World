#include "Organism.h"

Organism::Organism(int power, int health, Position position)
{
	setPower(power);
	setHealth(health);
	setMaxHealth(health + 2);
	setPosition(position);
	setSpecies("O");
}

int Organism::getPower()
{
	return this->power;
}

void Organism::setPower(int power)
{
	this->power = power;
}

int Organism::getHealth()
{
	return this->health;
}

void Organism::setHealth(int health)
{
	this->health = health;
}

int Organism::getMaxHealth()
{
	return this->maxHealth;
}

void Organism::setMaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth;
}

Position Organism::getPosition()
{
	return this->position;
}

void Organism::setPosition(Position position)
{
	this->position = position;
}

string Organism::toString()
{
	return "{ species: " + this->getSpecies() +
		", power: " + to_string(getPower()) +
		", health: " + to_string(getHealth()) + 
		", maxHealth: " + to_string(getMaxHealth()) +
		", position: " + getPosition().toString() + "}";
}

void Organism::move(int dx, int dy)
{
	position.move(dx, dy);
}

string Organism::getSpecies()
{
	return this->species;
}

void Organism::setSpecies(string spec)
{
	this->species = spec;
}