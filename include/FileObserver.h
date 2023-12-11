//
// Created by meteo on 30.11.2023.
//
#pragma once
#include "fstream"
#include "IObserver.h"
class NPC;

class FileObserver : public IObserver {
public:
    FileObserver() = default;

    void update(NPC* npc) override;

};

