#include "Organism.h"

Organism::Organism(int power, int health, Position position, int birthTurn)
{
	setPower(power);
	setHealth(health);
	setMaxHealth(health + 2);
	setPosition(position);
	setSpecies("O");
	setBirthTurn(birthTurn);
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

void Organism::addAncestor(int birthTurn, string species) {
	ancestors.push_back(AncestorInfo(birthTurn, -1, species));
}

void Organism::updateAncestorDeathTurn(string species, int deathTurn) {
	for (auto& ancestor : ancestors) {
		if (ancestor.species == species && ancestor.deathTurn == -1) {
			ancestor.deathTurn = deathTurn;
			break;
		}
	}
}

void Organism::regenerateHealth() {
	if (health < maxHealth) {
		health++;
	}
}

bool Organism::canReproduce() {
	return health == maxHealth || health > maxHealth;
}

Organism Organism::createChild(int birthTurn) {
	Position childPosition = position; // Assuming child starts at the same position, you might want to handle this differently
	Organism child(power, 1, childPosition, birthTurn); // Child starts with 1 health
	child.setSpecies(species);

	// Add parent's ancestors to the child
	for (const auto& ancestor : this->getAncestors()) {
		child.addAncestor(ancestor.birthTurn, ancestor.species);
		child.updateAncestorDeathTurn(ancestor.species, ancestor.deathTurn);
	}

	// Add parent to child's ancestor list
	child.addAncestor(this->getBirthTurn(), this->getSpecies());

	return child;
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
		result += "{species: " + ancestor.species +
			", birthTurn: " + to_string(ancestor.birthTurn) +
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

bool Organism::canAttack() {
	return power > 0;
}

void Organism::attack(Organism& target) {
	if (canAttack()) {
		target.setHealth(target.getHealth() - power);
	}
}