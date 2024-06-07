#include "Dandelion.h"

Dandelion::Dandelion(Position position, int birthTurn)
    : Plant(0, 1, 2, position, birthTurn, "D") {}

bool Dandelion::canReproduce() const {
    return getHealth() == getMaxHealth();
}

Organism* Dandelion::createChild(int birthTurn) const {
    Position childPosition = getPosition();
    Dandelion* child = new Dandelion(childPosition, birthTurn);
    child->addAncestor(getId(), getBirthTurn());

    // Copy ancestors from parent to child
    for (const auto& ancestor : getAncestors()) {
        child->getAncestors().push_back(ancestor);
    }

    return child;
}

bool Dandelion::canAttack() const {
    return false;
}

void Dandelion::attack(Organism& target) {
    // Dandelions do not attack
}
