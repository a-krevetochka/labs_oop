//
// Created by meteo on 18.10.2023.
//
#pragma once
#include "iostream"
#include "Point.h"
#include "Vector.h"
#include "FigureValidator.h"
class BaseFigure {
public:
    BaseFigure();

    explicit BaseFigure(Vector<Point>);

    Point centerOfRounding();

    [[nodiscard]] Vector<Point> getPeaks() const{
        return _peaks;
    }

    virtual BaseFigure& operator=(BaseFigure const &right) = 0;

    virtual explicit operator double() const = 0;

    virtual void setPeaks(Vector<Point>) = 0;

    virtual bool operator==(const BaseFigure &right)const = 0;

    friend std::ostream& operator<<(std::ostream& out, BaseFigure*);

protected:
    Vector<Point> _peaks;
};

