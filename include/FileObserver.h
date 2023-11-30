//
// Created by meteo on 30.11.2023.
//
#include "Observable.h"
#include "fstream"

class FileObserver : public Observable {
public:
    FileObserver() = default;

    FileObserver(std::vector<NPC*> npcs);

    void subscribe(NPC *) override;

    void unsubscribe(NPC *) override;

    void write() override;
};

