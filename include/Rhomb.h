//
// Created by meteo on 18.10.2023.
//
#pragma once
#include "BaseFigure.h"
class Rhomb : public BaseFigure{
public:
    Rhomb();

    Rhomb(Vector<Point>);

    BaseFigure& operator=(BaseFigure const &right) override;

    explicit operator double() const override;

    bool operator==(const BaseFigure &right)const override;

    void setPeaks(Vector<Point>) override;

    friend std::ostream& operator<<(std::ostream& out, const Rhomb& rhomb);

    friend std::istream operator>>(std::istream& in, Rhomb& rhomb);

    ~Rhomb() = default;
};

