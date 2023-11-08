#pragma once
#include "iostream"

template<class T>
class Point{
private:
    T _x;
    T _y;
public:
    Point();

    Point(T, T);

    Point<T> operator+(Point<T> &right) const;

    Point<T>& operator=(Point<T> const &right);

    Point<T>& operator-(Point<T> const &right) const;

    Point<T>& operator*(int right) const;

    bool operator==(Point<T> const &right) const;

    [[nodiscard]] T getX() const;

    [[nodiscard]] T getY() const;

    friend std::ostream& operator<<(std::ostream& out, const Point<T>& point);

    friend std::istream  operator>>(std::istream& is, Point<T>& point);

    ~Point() = default;
};