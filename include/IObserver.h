//
// Created by meteo on 30.11.2023.
//
#pragma once

#include <iostream>

class IObserver {
    virtual void update(std::ostream &strm) = 0;
};
