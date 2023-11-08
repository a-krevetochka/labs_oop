//
// Created by meteo on 19.10.2023.
//
#pragma once
#include "IFigureValidator.h"
#include "ParalellogramValidator.h"

template<class T>
class RhombValidator : public ParalellogramValidator<T>{
public:
    bool isAllowedForType(const std::type_info &typeInfo) override;

    void validateFigure(Vector<Point<T>> peaks) override;

    ~RhombValidator() = default;
};


