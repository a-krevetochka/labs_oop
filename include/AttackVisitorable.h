//
// Created by meteo on 29.11.2023.
//
#pragma once

#include "AttackVisitor.h"

class AttackVisitorable {
public:
    virtual void accept(AttackVisitor attackVisitor, NPC *) = 0;
};
