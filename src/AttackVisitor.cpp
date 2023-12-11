//
// Created by meteo on 29.11.2023.
//

#include "AttackVisitor.h"
#include "NPC.h"
#include "Bear.h"
#include "Squirrel.h"
#include "Orc.h"

bool isEnemy(NPC *npc1, NPC *npc2) {
    return npc1->getTitle() == npc2->getTitle();
}

bool AttackVisitor::isInAttackRange(Point myCoordinates, Point enemyCoordinates) {
    return _attackRange >= myCoordinates.distance(enemyCoordinates);
}

void AttackVisitor::changeAttackRanges(double attackRange) {
    _attackRange = attackRange;
}

void AttackVisitor::bearAttack(NPC *npc, Point coordinates) {
    std::vector<NPC *> bearEnemies = {new Squirrel};
    for (int i = 0; i < bearEnemies.size(); ++i) {
        if (isEnemy(npc, bearEnemies.at(i)) && isInAttackRange(coordinates, npc->getCoordinates())) {
            npc->setIsAlive(false);
        }
    }
}

void AttackVisitor::squirrelAttack(NPC *npc) {
}

void AttackVisitor::orcAttack(NPC *npc, Point coordinates) {
    std::vector<NPC *> orcEnemies = {new Orc, new Bear};
    for (int i = 0; i < orcEnemies.size(); ++i) {
        if (isEnemy(npc, orcEnemies.at(i)) && isInAttackRange(coordinates, npc->getCoordinates())) {
            npc->setIsAlive(false);
        }
    }
}
