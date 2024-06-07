#include "Organism.h"

int Organism::nextId = 0;

Organism::Organism(int power, int health, int maxHealth, Position position, int birthTurn, string species)
	: id(nextId++), power(power), health(health), maxHealth(maxHealth), position(position), species(species), birthTurn(birthTurn)
{
}

int Organism::getId() const 
{
	return id;
}

int Organism::getPower() const
{
	return this->power;
}

void Organism::setPower(int power)
{
	this->power = power;
}

int Organism::getHealth() const
{
	return this->health;
}

void Organism::setHealth(int health)
{
	this->health = health;
}

int Organism::getMaxHealth() const
{
	return this->maxHealth;
}

void Organism::setMaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth;
}

Position Organism::getPosition() const
{
	return this->position;
}

void Organism::setPosition(Position position)
{
	this->position = position;
}

vector<AncestorInfo>& Organism::getAncestors() {
	return this->ancestors;
}

const vector<AncestorInfo>& Organism::getAncestors() const {
	return this->ancestors;
}

void Organism::addAncestor(int id, int birthTurn) {
	ancestors.push_back(AncestorInfo(id, birthTurn, -1));
}

void Organism::updateAncestorDeathTurn(int ancestorId, int deathTurn) {
	for (auto& ancestor : ancestors) {
		if (ancestor.id == ancestorId && ancestor.deathTurn == -1) {
			ancestor.deathTurn = deathTurn;
			break;
		}
	}
}

void Organism::propagateAncestorDeathTurn(int ancestorId, int deathTurn) {
	for (auto& ancestor : ancestors) {
		if (ancestor.id == ancestorId && ancestor.deathTurn == -1) {
			ancestor.deathTurn = deathTurn;
		}
	}
}

void Organism::regenerateHealth() {
	if (health < maxHealth) {
		health++;
	}
}

string Organism::toString()
{
	string result = "{ species: " + this->getSpecies() +
		", power: " + to_string(getPower()) +
		", health: " + to_string(getHealth()) +
		", maxHealth: " + to_string(getMaxHealth()) +
		", position: " + getPosition().toString() +
		", ancestors: [";
	for (const auto& ancestor : ancestors) {
		result += "{ birthTurn: " + to_string(ancestor.birthTurn) +
			", deathTurn: " + (ancestor.deathTurn == -1 ? "alive" : to_string(ancestor.deathTurn)) + "}, ";
	}
	result += "]}";
	return result;
}


string Organism::getSpecies() const
{
	return this->species;
}

void Organism::setSpecies(string spec)
{
	this->species = spec;
}

int Organism::getBirthTurn() const
{
	return this->birthTurn;
}

void Organism::setBirthTurn(int birthTurn)
{
	this->birthTurn = birthTurn;
}

