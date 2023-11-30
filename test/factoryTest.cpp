//
// Created by meteo on 30.11.2023.
//

#include <gtest/gtest.h>
#include "NPCfactory.h"

TEST(NPCFactoryTest, CreateNPCTest) {
    NPCfactory factory;
    NPC *npc = factory.createNPC("orc", "TestOrc");
    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->getName(), "TestOrc");
    delete npc;
}


TEST(NPCFactoryTest, CreateNPCsFromFileTest) {
    NPCfactory factory;
    std::vector<NPC *> npcs = factory.createNPCsFromFile("npcs.txt");

    EXPECT_EQ(npcs.size(), 6);
    for (auto npc: npcs) {
        delete npc;
    }
}