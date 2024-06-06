#include "Toadstool.h"

Toadstool::Toadstool(Position position, int birthTurn)
    : Plant(0, 1, 1, position, birthTurn, "T") {}

bool Toadstool::canReproduce() const {
    return getHealth() == getMaxHealth();
}

Organism* Toadstool::createChild(int birthTurn) const {
    Position childPosition = getPosition();
    Toadstool* child = new Toadstool(childPosition, birthTurn);
    child->addAncestor(getId(), getBirthTurn());

    // Copy ancestors from parent to child
    for (const auto& ancestor : getAncestors()) {
        child->getAncestors().push_back(ancestor);
    }

    return child;
}

bool Toadstool::canAttack() const {
    return false;
}

void Toadstool::attack(Organism& target) {
}
