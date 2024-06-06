#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
    Grass(Position position, int birthTurn);

    bool canReproduce() const override;
    Organism* createChild(int birthTurn) const override;
    bool canAttack() const override;
    void attack(Organism& target) override;
};
