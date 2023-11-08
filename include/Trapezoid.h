//
// Created by meteo on 18.10.2023.
//
#pragma once
#include "BaseFigure.h"

template<class T>
class Trapezoid : public BaseFigure<T>{
public:
    Trapezoid();

    explicit Trapezoid(Vector<Point<T>>);

    bool operator==(const BaseFigure<T> &right)const override;

    BaseFigure<T>& operator=(BaseFigure<T> const &right) override;

    friend std::ostream& operator<<(std::ostream& out, const Trapezoid<T>& trapezoid);

    friend std::istream operator>>(std::istream& in, Trapezoid<T>& rectangle);

    void setPeaks(Vector<Point<T>>) override;

    explicit operator double() const override;

    ~Trapezoid() = default;

    static Trapezoid & createFromPoints(Vector<Point<T>>);
};



