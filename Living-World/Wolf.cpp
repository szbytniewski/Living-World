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
    } else if (Toadstool* toadstool = dynamic_cast<Toadstool*>(&target)) {
        target.setHealth(target.getHealth() - getPower());
        if (target.getHealth() <= 0) {
            this->setHealth(0);
        }
        cout << "test";
    }
}
