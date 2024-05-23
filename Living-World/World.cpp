#include "World.h"
#include <fstream>
#include <iostream>

string World::getOrganismFromPosition(int x, int y)
{
	for (Organism org : organisms)
		if (org.getPosition().getX() == x && org.getPosition().getY() == y)
			return org.getSpecies();
	return "";
}

bool World::isPositionOnWorld(int x, int y)
{
	return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
}

bool World::isPositionFree(Position position) {
	return this->getOrganismFromPosition(position.getX(), position.getY()).empty();
}

vector<Position> World::getVectorOfFreePositionsAround(Position position)
{
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for (int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) &&
				isPositionOnWorld(pos_x + x, pos_y + y)) {
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	auto iter = remove_if(result.begin(), result.end(),
		[this](Position pos) {return !isPositionFree(pos); });
	result.erase(iter, result.end());

	return result;
}

World::World(int worldX, int worldY)
{
	setWorldX(worldX);
	setWorldY(worldY);
}

int World::getWorldX()
{
	return this->worldX;
}

void World::setWorldX(int worldX)
{
	this->worldX = worldX;
}

int World::getWorldY()
{
	return this->worldY;
}

void World::setWorldY(int worldY)
{
	this->worldY = worldY;
}

int World::getTurn()
{
	return this->turn;
}

void World::addOrganism(Organism* organism)
{
	this->organisms.push_back(*organism);
}

vector<Organism*> World::getAdjacentOrganisms(Position position)
{
	vector<Organism*> result;
	int pos_x = position.getX();
	int pos_y = position.getY();
	for (int x = -1; x < 2; ++x) {
		for (int y = -1; y < 2; ++y) {
			if ((x != 0 || y != 0) && isPositionOnWorld(pos_x + x, pos_y + y)) {
				for (auto& organism : organisms) {
					if (organism.getPosition().getX() == pos_x + x && organism.getPosition().getY() == pos_y + y) {
						result.push_back(&organism);
					}
				}
			}
		}
	}
	return result;
}

void World::handleOrganismDeath(Organism& organism) {
	// Mark the organism's death in its ancestors
	organism.updateAncestorDeathTurn(organism.getId(), this->turn);

	// Propagate death information to all organisms
	for (auto& org : organisms) {
		org.propagateAncestorDeathTurn(organism.getId(), this->turn);
	}

	// Remove the dead organism from the list
	auto iter = std::remove_if(organisms.begin(), organisms.end(),
		[&organism](const Organism& o) { return &o == &organism; });
	organisms.erase(iter, organisms.end());
}


void World::makeTurn()
{
	turn++;
	vector<Organism> newOrganisms;
	vector<Position> newPositions;
	vector<int> organismsToRemove;
	int numberOfNewPositions;
	int randomIndex;

	srand(time(0));
	for (auto& org : organisms) {
		// Check if organism can reproduce
		if (org.canReproduce()) {
			// Zmienic aby robil organizm tej samej klasy oraz dziecko musi sie insta ruszyc
			Organism child = org.createChild(turn);
			newOrganisms.push_back(child);
			org.setHealth(1);
		} else {
			//Regenerate Health
			org.regenerateHealth();

			//Move Organism
			newPositions = getVectorOfFreePositionsAround(org.getPosition());
			numberOfNewPositions = newPositions.size();
			if (numberOfNewPositions > 0) {
				randomIndex = rand() % numberOfNewPositions;
				org.setPosition(newPositions[randomIndex]);
			}

			vector<Organism*> adjacentOrganisms = getAdjacentOrganisms(org.getPosition());
			for (auto& target : adjacentOrganisms) {
				if (org.getSpecies() != target->getSpecies()) { // Check species
					org.attack(*target);
					if (target->getHealth() <= 0) {
						handleOrganismDeath(*target);
						organismsToRemove.push_back(1); // Store index for removal
					}
				}
			}
		}
		
		// Check if organism is dead
		if (org.getHealth() <= 0) {
			handleOrganismDeath(org);
		}
	
	}

	// Add new organisms to the world
	for (auto& newOrg : newOrganisms) {
		organisms.push_back(newOrg);
	}

	// Remove dead organisms from the world
	organisms.erase(remove_if(organisms.begin(), organisms.end(),
		[](Organism& org) { return org.getHealth() <= 0; }), organisms.end());
}

void World::writeWorld(string fileName)
{
	fstream my_file;
	my_file.open(fileName, ios::out | ios::binary);
	if (my_file.is_open()) {
		my_file.write((char*)&this->worldX, sizeof(int));
		my_file.write((char*)&this->worldY, sizeof(int));
		my_file.write((char*)&this->turn, sizeof(int));
		int orgs_size = this->organisms.size();
		my_file.write((char*)&orgs_size, sizeof(int));
		for (int i = 0; i < orgs_size; i++) {
			int data;
			data = this->organisms[i].getPower();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i].getHealth();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i].getMaxHealth();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i].getPosition().getX();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i].getPosition().getY();
			my_file.write((char*)&data, sizeof(int));
			string s_data = this->organisms[i].getSpecies();
			int s_size = s_data.size();
			my_file.write((char*)&s_size, sizeof(int));
			my_file.write(s_data.data(), s_data.size());
		}
		my_file.close();
	}
}

void World::readWorld(string fileName)
{
	fstream my_file;
	my_file.open(fileName, ios::in | ios::binary);
	if (my_file.is_open()) {
		int result;
		my_file.read((char*)&result, sizeof(int));
		this->worldX = (int)result;
		my_file.read((char*)&result, sizeof(int));
		this->worldY = (int)result;
		my_file.read((char*)&result, sizeof(int));
		this->turn = (int)result;
		my_file.read((char*)&result, sizeof(int));
		int orgs_size = (int)result;
		vector<Organism> new_organisms;
		for (int i = 0; i < orgs_size; i++) {
			int power;
			my_file.read((char*)&result, sizeof(int));
			power = (int)result;

			int health;
			my_file.read((char*)&result, sizeof(int));
			health = (int)result;

			int maxHealth;
			my_file.read((char*)&result, sizeof(int));
			maxHealth = (int)result;

			int pos_x;
			my_file.read((char*)&result, sizeof(int));
			pos_x = (int)result;
			int pos_y;
			my_file.read((char*)&result, sizeof(int));
			pos_y = (int)result;
			Position pos{ pos_x, pos_y };

			int s_size;
			my_file.read((char*)&result, sizeof(int));
			s_size = (int)result;

			string species;
			species.resize(s_size);
			my_file.read((char*)&species[0], s_size);

			Organism org(power, health, pos, this->turn);
			org.setMaxHealth(maxHealth);
			org.setSpecies(species);
			new_organisms.push_back(org);
		}
		this->organisms = new_organisms;
		my_file.close();
	}
}

void World::printOrganismsInfo() // New method to print organisms info
{
	std::cout << "Organisms Info:\n";
	for (auto& org : organisms) {
		std::cout << org.toString() << "\n";
	}
}

string World::toString()
{
	string result = "\nturn: " + to_string(getTurn()) + "\n";
	string spec;

	for (int wY = 0; wY < getWorldY(); ++wY) {
		for (int wX = 0; wX < getWorldX(); ++wX) {
			spec = getOrganismFromPosition(wX, wY);
			if (spec != "")
				result += spec;
			else
				result += separator;
		};
		result += "\n";
	}
	return result;
}