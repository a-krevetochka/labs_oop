//
// Created by meteo on 19.10.2023.
//
#pragma once
#include "IFigureValidator.h"

class RhombValidator : public IFigureValidator{
public:
    bool isAllowedForType(const std::type_info &typeInfo) override;

    void validateFigure(Vector<Point> peaks) override;
};


