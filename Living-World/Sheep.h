#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(Position position, int birthTurn);

    bool canReproduce() const override;
    Organism* createChild(int birthTurn) const override;

    bool canAttack() const override;
    void attack(Organism& target) override;
};