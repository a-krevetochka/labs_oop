//
// Created by meteo on 18.10.2023.
//
#pragma once
#include "Paralellogram.h"

class Rectangle : public Paralellogram{
public:
    Rectangle();

    explicit Rectangle(Vector<Point>);

    bool operator==(const BaseFigure &right)const override;

    Paralellogram& operator=(BaseFigure const &right) override;

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle);

    friend std::istream operator>>(std::istream& in, Rectangle& rectangle);

    void setPeaks(Vector<Point>) override;

    explicit operator double() const override;

    ~Rectangle() = default;

    static Rectangle& createFromPoints(Vector<Point>);
};

