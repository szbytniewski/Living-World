#include "Grass.h"

Grass::Grass(Position position, int birthTurn)
    : Plant(0, 1, 2, position, birthTurn, "G") 
{
}

bool Grass::canReproduce() const {
    return getHealth() == getMaxHealth();
}

Organism* Grass::createChild(int birthTurn) const {
    Position childPosition = getPosition();
    Grass* child = new Grass(childPosition, birthTurn);
    child->addAncestor(getId(), getBirthTurn());

    // Copy ancestors from parent to child
    for (const auto& ancestor : getAncestors()) {
        child->getAncestors().push_back(ancestor);
    }

    return child;
}


bool Grass::canAttack() const {
    return false;
}

void Grass::attack(Organism& target) {
    
}