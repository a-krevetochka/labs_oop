//
// Created by meteo on 29.11.2023.
//

#include "Squirrel.h"

#include <utility>

void Squirrel::accept(AttackVisitor attackVisitor, NPC *npc) {
    attackVisitor.squirrelAttack(npc);
}

Squirrel::Squirrel(std::string name, Point coordinates) {
    _name = std::move(name);
    _title = "squirrel";
    _isAlive = true;
    _coordinates = coordinates;
}

void Squirrel::update(std::ostream &strm) {
    strm << this << std::endl << std::endl;
}

Squirrel::Squirrel() {
    _title = "squirrel";
}




