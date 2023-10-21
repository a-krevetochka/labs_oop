//
// Created by meteo on 19.10.2023.
//

#include "RhombValidator.h"
#include "Rhomb.h"
#include "cmath"

bool RhombValidator::isAllowedForType(const std::type_info &typeInfo) {
    return typeid(Rhomb) == typeInfo;
}

void RhombValidator::validateFigure(Vector<Point> peaks) {
    ParalellogramValidator::validateFigure(peaks);
    Vector<double> lengths;
    for (int indexOfPeak = 0; indexOfPeak < peaks.size() - 1; ++indexOfPeak) {
        double currentLength = std::sqrt(pow(peaks.at(indexOfPeak).getX() - peaks.at(indexOfPeak + 1).getX(), 2) +
                                      pow(peaks.at(indexOfPeak).getY() - peaks.at(indexOfPeak + 1).getY(), 2));
        lengths.push_back(currentLength);
    }

    lengths.push_back(std::sqrt(pow(peaks.at(3).getX() - peaks.at(0).getX(), 2) +
                                pow(peaks.at(3).getY() - peaks.at(0).getY(), 2)));

    for (int index = 0; index < peaks.size(); ++index) {
        if (lengths.at(index) != lengths[0]){
            throw std::invalid_argument("Rhomb has only equals sides");
        }
    }

    Point diag1 = peaks.at(2) - peaks.at(0);
    Point diag2 = peaks.at(3) - peaks.at(1);
    if (diag1.getX()*diag2.getX() + diag1.getY()*diag2.getY() != 0){
        throw std::invalid_argument("diagonals has to be orthogonal");
    }
}
