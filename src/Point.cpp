#include "Point.h"

template<class T>
Point<T>::Point(T x, T y) {
    _x = x;
    _y = y;
}

template<class T>
Point<T>::Point()=default;

template<class T>
Point<T> Point<T>::operator+(Point &right) const {
    return *(new Point((this->_x + right._x), (this->_y + right._y)));
}

template<class T>
Point<T>& Point<T>::operator=(Point const &right){
    this->_x = right._x;
    this->_y = right._y;
    return *this;
}

template<class T>
std::ostream &operator<<(std::ostream &out, const Point<T> &point) {
    out << "x: " << point._x << " y: " << point._y;
    return out;
}

template<class T>
Point<T> &Point<T>::operator-(const Point &right) const {
    return *(new Point((this->_x - right._x), (this->_y - right._y)));
}

template<class T>
std::istream operator>>(std::istream &is, Point<T> &point) {
    std::cout << "enter x:" << std::endl;
    is >> point._x;
    std::cout << "enter y:" << std::endl;
    is >> point._y;
    return std::istream(nullptr);
}

template<class T>
bool Point<T>::operator==(const Point &right) const {
    if (this->_x == right._x && this->_y == right._y){
        return true;
    }
    return false;
}

template<class T>
T Point<T>::getX() const {
    return _x;
}

template<class T>
T Point<T>::getY() const {
    return _y;
}

template<class T>
Point<T> &Point<T>::operator*(int right) const {
    return *(new Point(this->_x * right, this->_y * right));
}






