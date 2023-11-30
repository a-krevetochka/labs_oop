//
// Created by meteo on 30.11.2023.
//
#include "Observable.h"

class ConsoleObserver : public Observable {
public:
    ConsoleObserver() = default;

    ConsoleObserver(std::vector<NPC*>);

    void subscribe(NPC *) override;

    void unsubscribe(NPC *) override;

    void write() override;

};

