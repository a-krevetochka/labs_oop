//
// Created by meteo on 30.11.2023.
//

#include "FileObserver.h"
#include "NPC.h"

void FileObserver::update(NPC *npc) {
    std::ofstream file("battle.txt");
    file << npc << std::endl;
}
