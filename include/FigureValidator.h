//
// Created by meteo on 19.10.2023.
//
#pragma once
#include "IFigureValidator.h"
#include "RectangleValidator.h"
#include "RhombValidator.h"
#include "TrapezoidValidator.h"

class FigureValidator : public IFigureValidator{
    static Vector<IFigureValidator*> _validators;

public:
    static void Validate(const std::type_info &, Vector<Point>);
};

