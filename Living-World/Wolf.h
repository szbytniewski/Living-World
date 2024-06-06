#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(Position position, int birthTurn);

    bool canReproduce() const override;
    Organism* createChild(int birthTurn) const override;
    bool canAttack() const override;
    void attack(Organism& target) override;
};
