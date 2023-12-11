//
// Created by meteo on 30.11.2023.
//

#include "NPCfactory.h"
#include "Point.h"
#include "random"
#include "fstream"

Point generateRandomPoint(){
    srand(rand());

    int x = rand() % 500;

    int y = rand() % 500;

    return Point(x, y);
}

std::vector<NPC *> NPCfactory::createNPCsFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()){
        std::cerr << "file wasnt open";
    }
    std::string type, name;

    std::vector<NPC*> NPCs;

    while (file >> type >> name) {
        NPC* npc = this->createNPC(type, name);
        NPCs.push_back(npc);
    }
    return NPCs;
}

NPC *NPCfactory::createNPC(std::string type, std::string name) {
    if (type == "orc") return new Orc(name, generateRandomPoint());
    if (type == "squirrel") return new Squirrel(name, generateRandomPoint());
    if (type == "bear") return new Bear(name, generateRandomPoint());
    else{
        std::cerr << "invalid character";
    }
}
