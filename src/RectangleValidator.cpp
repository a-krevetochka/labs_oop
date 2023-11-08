//
// Created by meteo on 19.10.2023.
//

#include "RectangleValidator.h"
#include "Rectangle.h"
#include "cmath"

template<class T>
void RectangleValidator<T>::validateFigure(Vector<Point<T>> peaks) {
    ParalellogramValidator<T>::validateFigure(peaks);
    if (peaks.at(0).getX() != peaks.at(1).getX() || peaks.at(1).getY() != peaks.at(2).getY() || peaks.at(2).getX() != peaks.at(3).getX() || peaks.at(3).getY() != peaks.at(0).getY()){
        throw std::invalid_argument("rectangle sides has to be orthogonal");
    }

}

template<class T>
bool RectangleValidator<T>::isAllowedForType(const std::type_info &typeInfo) {
    return typeid(Rectangle<T>) == typeInfo;
}


