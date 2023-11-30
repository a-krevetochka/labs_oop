//
// Created by meteo on 30.11.2023.
//

#include "ConsoleObserver.h"
#include <sstream>
#include <fstream>

void ConsoleObserver::subscribe(NPC *sub) {
    subscribers.push_back(sub);
}

void ConsoleObserver::unsubscribe(NPC *sub) {
    for (auto i = subscribers.cbegin(); i != subscribers.cend(); ++i) {
        if (*i == sub) {
            subscribers.erase(i);
        }
    }
}

void ConsoleObserver::write() {
    std::stringstream ss;

    for (auto sub: subscribers) {
        sub->update(ss);
    }

    std::cout << ss.str();
}

ConsoleObserver::ConsoleObserver(std::vector<NPC *> npcs) {
    subscribers = npcs;
}
