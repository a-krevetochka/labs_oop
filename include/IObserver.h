//
// Created by meteo on 30.11.2023.
//
#pragma once

#include <iostream>
class NPC;

class IObserver {
public:
    virtual void update(NPC* npc) = 0;
};
