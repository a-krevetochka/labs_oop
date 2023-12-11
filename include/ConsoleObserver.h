//
// Created by meteo on 30.11.2023.
//
#pragma once
#include "IObserver.h"
class NPC;

class ConsoleObserver : public IObserver {
public:
    ConsoleObserver() = default;

    void update(NPC* ) override;

};

