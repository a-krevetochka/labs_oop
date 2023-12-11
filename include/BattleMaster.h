//
// Created by meteo on 30.11.2023.
//
#pragma once
#include "AttackVisitor.h"
#include "FileObserver.h"
#include "ConsoleObserver.h"
#include "NPCfactory.h"

class BattleMaster {
private:
    AttackVisitor* _attackVisitor;
    NPCfactory _npcFactory;
    std::vector<NPC*> _npcs;
public:
    BattleMaster(std::string filename, double attackRange){
        _attackVisitor = new AttackVisitor();
       _attackVisitor->changeAttackRanges(attackRange);
       _npcs = _npcFactory.createNPCsFromFile(filename);
    }
    void startBattle(){
        for (int i = 0; i < _npcs.size(); ++i) {
            for (int j = 0; j < _npcs.size(); ++j) {
                if (i == j){
                    continue;
                }

                _npcs.at(i)->accept(*_attackVisitor, _npcs.at(j));
            }
        }
    }

    void writeResults(){
        for (int i = 0; i < _npcs.size(); ++i) {
            _npcs.at(i)->write();
        }
    }
};

