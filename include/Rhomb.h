//
// Created by meteo on 18.10.2023.
//
#pragma once
#include "BaseFigure.h"
#include "Paralellogram.h"

template<class T>
class Rhomb : public Paralellogram<T>{
public:
    Rhomb();

    explicit Rhomb(Vector<Point<T>>);

    Rhomb<T>& operator=(BaseFigure<T> const &right) override;

    explicit operator double() const override;

    bool operator==(const BaseFigure<T> &right)const override;

    void setPeaks(Vector<Point<T>>) override;

    friend std::ostream& operator<<(std::ostream& out, const Rhomb<T>& rhomb);

    friend std::istream operator>>(std::istream& in, Rhomb<T>& rhomb);

    ~Rhomb() = default;

    static Rhomb<T>& createFromPoints(Vector<Point<T>>);
};

