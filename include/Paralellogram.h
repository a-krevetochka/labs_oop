//
// Created by meteo on 21.10.2023.
//
#pragma once
#include "BaseFigure.h"

class Paralellogram : public BaseFigure{

    virtual Paralellogram& operator=(BaseFigure const &right) = 0;

    virtual explicit operator double() const = 0;

    virtual void setPeaks(Vector<Point>) = 0;

    virtual bool operator==(const BaseFigure &right)const = 0;
};
