//
// Created by meteo on 21.10.2023.
//
#pragma once
#include "IFigureValidator.h"


class ParalellogramValidator : public IFigureValidator{
public:

    bool isAllowedForType(const std::type_info& typeInfo) override;

    ~ParalellogramValidator() = default;


    ParalellogramValidator();

    void validateFigure(Vector<Point> peaks) override;
};

