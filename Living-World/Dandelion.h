#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion(Position position, int birthTurn);

    bool canReproduce() const override;
    Organism* createChild(int birthTurn) const override;
    bool canAttack() const override;
    void attack(Organism& target) override;
};