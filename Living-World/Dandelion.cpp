#include "Dandelion.h"

Dandelion::Dandelion(Position position, int birthTurn)
    : Plant(0, 1, 1, position, birthTurn, "D") {}

bool Dandelion::canReproduce() const {
    return getHealth() == getMaxHealth();
}

Organism* Dandelion::createChild(int birthTurn) const {
    Position childPosition = getPosition();
    return new Dandelion(childPosition, birthTurn);
}

bool Dandelion::canAttack() const {
    return false;
}

void Dandelion::attack(Organism& target) {
    // Dandelions do not attack
}
