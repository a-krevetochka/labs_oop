//
// Created by meteo on 19.10.2023.
//
#pragma once
#include "IFigureValidator.h"

template<class T>
class TrapezoidValidator : public IFigureValidator<T>{
public:
    void validateFigure(Vector<Point<T>> peaks) override;

    bool isAllowedForType(const std::type_info &typeInfo) override;

    ~TrapezoidValidator() = default;
};
