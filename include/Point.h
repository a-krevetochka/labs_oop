//
// Created by meteo on 30.11.2023.
//
#pragma once

#include "iostream"
#include "cmath"

class Point {
private:
    double _x;
    double _y;
public:
    Point();

    Point(double, double);

    Point operator+(Point &right) const;

    Point &operator=(Point const &right);

    Point &operator-(Point const &right) const;

    Point &operator*(int right) const;

    bool operator==(Point const &right) const;

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

    friend std::ostream &operator<<(std::ostream &out, const Point &point);

    friend std::istream operator>>(std::istream &is, Point &point);

    double distance(Point point);

    ~Point() = default;
};