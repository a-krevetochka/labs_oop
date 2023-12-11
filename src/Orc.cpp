//
// Created by meteo on 29.11.2023.
//

#include "Orc.h"

void Orc::accept(AttackVisitor attackVisitor, NPC *npc) {
    attackVisitor.orcAttack(npc, _coordinates);
}

Orc::Orc(std::string name, Point coordinates) {
    _name = std::move(name);
    _title = "orc";
    _isAlive = true;
    _coordinates = coordinates;
}

Orc::Orc() {
    _title = "orc";
}

void Orc::write() {
    for (auto observer : _observers) {
        observer->update(this);
    }
}


