//
// Created by meteo on 19.10.2023.
//
#pragma once
#include "IFigureValidator.h"
#include "ParalellogramValidator.h"

template<class T>
class RectangleValidator : public ParalellogramValidator<T> {
public:
    void validateFigure(Vector<Point<T>> peaks) override;

    bool isAllowedForType(const std::type_info& typeInfo) override;

    ~RectangleValidator() = default;
};

