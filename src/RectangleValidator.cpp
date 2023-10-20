//
// Created by meteo on 19.10.2023.
//

#include "RectangleValidator.h"
#include "Rectangle.h"
#include "cmath"

void RectangleValidator::validateFigure(Vector<Point> peaks) {
    if (peaks.size() != 4) {
        throw std::invalid_argument("rectangle need only 4 points");
    }
    Vector<double> lengths;
    for (int indexOfPeak = 0; indexOfPeak < peaks.size() - 1; ++indexOfPeak) {
        double currentLength = std::sqrt(pow(peaks.at(indexOfPeak).getX() - peaks.at(indexOfPeak + 1).getX(), 2) +
                pow(peaks.at(indexOfPeak).getY() - peaks.at(indexOfPeak + 1).getY(), 2));
        lengths.push_back(currentLength);
    }

    lengths.push_back(std::sqrt(pow(peaks.at(3).getX() - peaks.at(0).getX(), 2) +
                      pow(peaks.at(3).getY() - peaks.at(0).getY(), 2)));
    if (lengths.at(0) != lengths.at(2) && lengths.at(1) != lengths.at(3)){
        throw std::invalid_argument("rectangle has both pairs equivalence sides");
    }
    if (peaks.at(1) - peaks.at(0) != peaks.at(2) - peaks.at(3) || peaks.at(2) - peaks.at(1) != peaks.at(3) - peaks.at(0)){
        throw std::invalid_argument("rectangle sides has to be parallel");
    }
    if (peaks.at(0).getX() != peaks.at(1).getX() || peaks.at(1).getY() != peaks.at(2).getY() || peaks.at(2).getX() != peaks.at(3).getX() || peaks.at(3).getY() != peaks.at(0).getY()){
        throw std::invalid_argument("rectangle sides has to be orthogonal");
    }

}

bool RectangleValidator::isAllowedForType(const std::type_info &typeInfo) {
    return typeid(Rectangle) == typeInfo;
}


