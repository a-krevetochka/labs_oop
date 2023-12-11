//
// Created by meteo on 29.11.2023.
//

#include "Bear.h"

#include <utility>

void Bear::accept(AttackVisitor attackVisitor, NPC *npc) {
    attackVisitor.bearAttack(npc, _coordinates);
}

Bear::Bear(std::string name, Point coordinates) {
    _name = std::move(name);
    _title = "bear";
    _isAlive = true;
    _coordinates = coordinates;
}


Bear::Bear() {
    _title = "bear";
}

void Bear::write() {
    for (auto observer : _observers) {
        observer->update(this);
    }
}

