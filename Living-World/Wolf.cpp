#include "Wolf.h"
#include "Sheep.h"
#include "Toadstool.h"
#include <iostream>
#include <string>

Wolf::Wolf(Position position, int birthTurn)
    : Animal(8, 5, 20, position, birthTurn, "W") {}

bool Wolf::canReproduce() const {
    return getHealth() == getMaxHealth();
}

Organism* Wolf::createChild(int birthTurn) const {
    Position childPosition = getPosition();
    return new Wolf(childPosition, birthTurn);
}

bool Wolf::canAttack() const {
    return true;
}

void Wolf::attack(Organism& target) {
    if (Sheep* sheep = dynamic_cast<Sheep*>(&target)) {
        int targetHealth = sheep->getHealth();
        targetHealth -= getPower();
        if (targetHealth <= 0) {
            sheep->setHealth(0);
            sheep->updateAncestorDeathTurn(sheep->getId(), 1);
        }
        else {
            sheep->setHealth(targetHealth);
        }
    } else if (Plant* plant = dynamic_cast<Plant*>(&target)) {
        if (plant->getSpecies() == "T") {
            // Both attacker and Toadstool die
            this->setHealth(0);
            plant->setHealth(0);
            plant->updateAncestorDeathTurn(plant->getId(), 1);
        }
    }
}
