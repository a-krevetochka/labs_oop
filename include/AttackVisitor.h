//
// Created by meteo on 29.11.2023.
//
#pragma once

#include "vector"
#include "iostream"
#include "Point.h"

class NPC;

class AttackVisitor {
private:
    double _attackRange;

public:
    bool isInAttackRange(Point myCoordinates, Point enemyCoordinates);

    void orcAttack(NPC *npc, Point coordinates);

    void squirrelAttack(NPC *);

    void bearAttack(NPC *, Point);

    void changeAttackRanges(double attackRange);
};

