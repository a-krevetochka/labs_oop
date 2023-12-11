//
// Created by meteo on 29.11.2023.
//
#pragma once

#include "NPC.h"

class Squirrel : public NPC {
public:
    Squirrel();

    Squirrel(std::string name, Point coordinates);

    void accept(AttackVisitor attackVisitor, NPC *) override;

    void write() override;

};
