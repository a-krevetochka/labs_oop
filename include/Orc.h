//
// Created by meteo on 29.11.2023.
//

#pragma once

#include "NPC.h"

class Orc : public NPC {
public :
    Orc();

    Orc(std::string name, Point coordinates);

    void accept(AttackVisitor attackVisitor, NPC *) override;

    void update(std::ostream &strm) override;

};

