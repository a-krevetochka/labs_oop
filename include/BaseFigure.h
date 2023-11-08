//
// Created by meteo on 18.10.2023.
//
#pragma once
#include "iostream"
#include "Point.h"
#include "Vector.h"
#include "FigureValidator.h"

template<class T>
class BaseFigure {
public:
    BaseFigure();

    explicit BaseFigure(Vector<Point<T>>);

    Point<T> centerOfRounding();

    [[nodiscard]] Vector<Point<T>> getPeaks() const{
        return _peaks;
    }

    virtual BaseFigure<T>& operator=(BaseFigure<T> const &right) = 0;

    virtual explicit operator double() const = 0;

    virtual void setPeaks(Vector<Point<T>>) = 0;

    virtual bool operator==(const BaseFigure &right)const = 0;

    friend std::ostream& operator<<(std::ostream& out, BaseFigure*);

    ~BaseFigure();

protected:
    Vector<Point<T>> _peaks;
};

