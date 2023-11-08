//
// Created by meteo on 18.10.2023.
//
#pragma once
#include "Paralellogram.h"

template<class T>
class Rectangle : public Paralellogram<T>{
public:
    Rectangle();

    explicit Rectangle(Vector<Point<T>>);

    bool operator==(const BaseFigure<T> &right)const override;

    Paralellogram<T>& operator=(BaseFigure<T> const &right) override;

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle);

    friend std::istream operator>>(std::istream& in, Rectangle& rectangle);

    void setPeaks(Vector<Point<T>>) override;

    explicit operator double() const override;

    ~Rectangle() = default;

    static Rectangle& createFromPoints(Vector<Point<T>>);
};

