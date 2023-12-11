//
// Created by meteo on 30.11.2023.
//

#include "ConsoleObserver.h"
#include "NPC.h"

void ConsoleObserver::update(NPC* npc) {
    std::cout << npc << std::endl;
}
