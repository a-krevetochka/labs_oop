//
// Created by meteo on 30.11.2023.
//
#pragma once

#include "iostream"
#include "vector"
#include "NPC.h"

class Observable {
protected:
    std::vector<NPC *> subscribers{};
public:
    int getSubscribersCount();

    virtual void subscribe(NPC *) = 0;

    virtual void unsubscribe(NPC *) = 0;

    virtual void write() = 0;
};
