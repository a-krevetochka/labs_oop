//
// Created by meteo on 19.10.2023.
//
#pragma once
#include "iostream"
#include "Vector.h"
#include "Point.h"

template<class T>
class IFigureValidator{
public:
    virtual void validateFigure(Vector<Point<T>> peaks) = 0;

    virtual bool isAllowedForType(const std::type_info& typeInfo) = 0;
};
