//#include "BattleMaster.h"
#include "NPC.h"
#include "NPCfactory.h"
#include "BattleMaster.h"

int main() {
    BattleMaster battleMaster("npcs.txt", 100);
    battleMaster.startBattle();
    battleMaster.writeResults();


}
