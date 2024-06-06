#include "Sheep.h"
#include "Plant.h"
#include "Toadstool.h"

Sheep::Sheep(Position position, int birthTurn)
    : Animal(3, 3, 8, position, birthTurn, "S") 
{
    setPower(3);
    setHealth(3);
    setMaxHealth(6);
    setSpecies("S");
}

bool Sheep::canReproduce() const {
    return getHealth() == getMaxHealth();
}

Organism* Sheep::createChild(int birthTurn) const {
    Position childPosition = getPosition();
    Sheep* child = new Sheep(childPosition, birthTurn);
    child->addAncestor(getId(), getBirthTurn());

    // Copy ancestors from parent to child
    for (const auto& ancestor : getAncestors()) {
        child->getAncestors().push_back(ancestor);
    }

    return child;
}


bool Sheep::canAttack() const {
    return true;
}

void Sheep::attack(Organism& target) {
    if (Plant* plant = dynamic_cast<Plant*>(&target)) {
        int targetHealth = plant->getHealth();
        targetHealth -= getPower();
        if (targetHealth <= 0) {
            plant->setHealth(0);
            plant->updateAncestorDeathTurn(plant->getId(), 1);
        }
        else {
            plant->setHealth(targetHealth);
        }
    } else if (Toadstool* toadstool = dynamic_cast<Toadstool*>(&target)) {
        target.setHealth(target.getHealth() - getPower());
        if (target.getHealth() <= 0) {
            this->setHealth(0);
        }
    }
}