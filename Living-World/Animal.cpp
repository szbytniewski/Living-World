#include "Animal.h"


Animal::Animal(int power, int health, int maxHealth, Position position, int birthTurn, std::string species)
    : Organism(power, health, maxHealth, position, birthTurn, species) {}

void Animal::move(int dx, int dy) {
    position.setX(position.getX() + dx);
    position.setY(position.getY() + dy);
}