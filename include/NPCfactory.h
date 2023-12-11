//
// Created by meteo on 30.11.2023.
//
#pragma once

#include "NPC.h"
#include "Bear.h"
#include "Squirrel.h"
#include "Orc.h"

class NPCfactory {
public :
    NPC* createNPC(std::string, std::string);

    std::vector<NPC*> createNPCsFromFile(std::string filename);
};


