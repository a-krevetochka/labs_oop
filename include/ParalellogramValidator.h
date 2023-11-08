//
// Created by meteo on 21.10.2023.
//
#pragma once
#include "IFigureValidator.h"

template<class T>
class ParalellogramValidator : public IFigureValidator<T>{
public:

    bool isAllowedForType(const std::type_info& typeInfo) override;

    ~ParalellogramValidator() = default;


    ParalellogramValidator();

    void validateFigure(Vector<Point<T>> peaks) override;
};

