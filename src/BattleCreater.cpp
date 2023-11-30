//
// Created by meteo on 30.11.2023.
//

#include "BattleCreater.h"

void BattleCreater::create() {
    std::string filename;
    std::cout << "enter the filename with npcs: ";
    std::cin >> filename;

    NPCfactory npCfactory;

    std::vector<NPC*> npcs = npCfactory.createNPCsFromFile(filename);

    double attackRange;
    std::cout << std::endl << "enter the attack range for npcs: ";
    std::cin >> attackRange;

    AttackVisitor attackVisitor;
    attackVisitor.changeAttackRanges(attackRange);

    for (int i = 0; i < npcs.size(); ++i) {
    for (int j = 0; j < npcs.size(); ++j) {
        if (i != j){
            npcs.at(i)->accept(attackVisitor, npcs.at(j));
            }
        }
    }

    ConsoleObserver consoleObserver(npcs);
    FileObserver fileObserver(npcs);

    consoleObserver.write();
    fileObserver.write();
}