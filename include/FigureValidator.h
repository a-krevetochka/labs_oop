//
// Created by meteo on 19.10.2023.
//
#pragma once
#include "IFigureValidator.h"
#include "RectangleValidator.h"
#include "RhombValidator.h"
#include "TrapezoidValidator.h"

template<class T>
class FigureValidator{
    static Vector<IFigureValidator<T>> _validators;

public:
    static void Validate(const std::type_info &, Vector<Point<T>>);
};

