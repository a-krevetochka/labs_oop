//
// Created by meteo on 21.10.2023.
//
#pragma once
#include "BaseFigure.h"

template<class T>
class Paralellogram : public BaseFigure<T>{

    virtual Paralellogram& operator=(BaseFigure<T> const &right) = 0;

    virtual explicit operator double() const = 0;

    virtual void setPeaks(Vector<Point<T>>) = 0;

    virtual bool operator==(const BaseFigure<T> &right)const = 0;
};
