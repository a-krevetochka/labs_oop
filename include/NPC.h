//
// Created by meteo on 30.11.2023.
//
#pragma once

#include "Point.h"
#include "AttackVisitorable.h"
#include "cmath"
#include "iostream"
#include "IObserver.h"

class NPC : public AttackVisitorable, IObserver {
protected:
    Point _coordinates;

    std::string _title;

    std::string _name;

    bool _isAlive;

public:

    void accept(AttackVisitor attackVisitor, NPC *) override = 0;

    void update(std::ostream &strm) override = 0;

    [[nodiscard]] const Point &getCoordinates() const;

    [[nodiscard]] bool isAlive() const;

    [[nodiscard]] const std::string &getTitle() const;

    void setCoordinates(const Point &coordinates);

    void setTitle(const std::string &title);

    void setIsAlive(bool isAlive);

    [[nodiscard]] const std::string &getName() const;

    void setName(const std::string &name);
};

std::ostream &operator<<(std::ostream &strm, const NPC *npc);