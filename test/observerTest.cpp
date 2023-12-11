#include "NPCfactory.h"
#include "ConsoleObserver.h"
#include <gtest/gtest.h>
//
// Created by meteo on 30.11.2023.
//
TEST(ConsoleObserverTest, SubscribeUnsubscribeTest) {
    NPCfactory factory;
    NPC *orc = factory.createNPC("orc", "TestOrc");
    NPC *squirrel = factory.createNPC("squirrel", "TestSquirrel");

    ConsoleObserver observer({orc, squirrel});

    EXPECT_EQ(observer.getSubscribersCount(), 2);

    observer.unsubscribe(squirrel);
    
    EXPECT_EQ(observer.getSubscribersCount(), 1);

    delete orc;
    delete squirrel;
}


TEST(ConsoleObserverTest, WriteTest) {
    NPCfactory factory;
    NPC *orc = factory.createNPC("orc", "TestOrc");

    ConsoleObserver observer({orc});

    testing::internal::CaptureStdout();
    observer.write();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "TestOrc");

    delete orc;
}