//
// Created by meteo on 19.10.2023.
//

#include "TrapezoidValidator.h"
#include "cmath"
#include "Trapezoid.h"

template<class T>
void TrapezoidValidator<T>::validateFigure(Vector<Point<T>> peaks) {
    if (peaks.size() != 4) {
        throw std::invalid_argument("_trapezoid need only 4 points");
    }
    double footing1 = std::sqrt(
            pow(peaks.at(1).getX() - peaks.at(2).getX(), 2) +
            pow(peaks.at(1).getY() - peaks.at(2).getY(), 2)
    );

    double footing2 = std::sqrt(
            pow(peaks.at(3).getX() - peaks.at(0).getX(), 2) +
            pow(peaks.at(3).getY() - peaks.at(0).getY(), 2)
    );

    if (footing1 == footing2){
        throw std::invalid_argument("footings of trapezoid have to be not equals");
    }

    if (peaks.at(0).getY() != peaks.at(3).getY() || peaks.at(1).getY() != peaks.at(2).getY() || (peaks.at(0).getX() == peaks.at(1).getX() && peaks.at(2).getX() == peaks.at(3).getX())){
        throw std::invalid_argument("footings have to be parallel and sides have not to be parallel");
    }
}

template<class T>
bool TrapezoidValidator<T>::isAllowedForType(const std::type_info &typeInfo) {
    return typeid(Trapezoid<T>) == typeInfo;
}
