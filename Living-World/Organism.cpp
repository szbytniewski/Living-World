#include "Organism.h"

int Organism::nextId = 0;

Organism::Organism(int power, int health, Position position, int birthTurn) : id(nextId++)
{
	setPower(power);
	setHealth(health);
	setMaxHealth(health + 2);
	setPosition(position);
	setSpecies("O");
	setBirthTurn(birthTurn);
}

int Organism::getId() const {
	return id;
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

vector<AncestorInfo>& Organism::getAncestors() {
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

int Organism::getBirthTurn()
{
	return this->birthTurn;
}

void Organism::setBirthTurn(int birthTurn)
{
	this->birthTurn = birthTurn;
}

