//
// Created by meteo on 30.11.2023.
//

#include "FileObserver.h"

void FileObserver::subscribe(NPC* sub) {
    subscribers.push_back(sub);
}

void FileObserver::unsubscribe(NPC* sub) {
    for (auto i = subscribers.cbegin(); i != subscribers.cend(); ++i) {
        if (*i == sub) {
            subscribers.erase(i);
        }
    }
}

void FileObserver::write() {
    std::ofstream file("example.txt");

    if (!file.is_open()){
        std::cerr << "file wasnt open";
    }

    for (auto sub : subscribers) {
        sub->update(file);
    }

    file.close();
}

FileObserver::FileObserver(std::vector<NPC *> npcs) {
    subscribers = npcs;
}
