//
// Created by meteo on 21.10.2023.
//

#include "ParalellogramValidator.h"
#include "Paralellogram.h"
#include "cmath"

template<class T>
bool ParalellogramValidator<T>::isAllowedForType(const std::type_info &typeInfo) {
    return typeid(Paralellogram<T>) == typeInfo;
}

template<class T>
void ParalellogramValidator<T>::validateFigure(Vector<Point<T>> peaks) {
    if (peaks.size() != 4) {
        throw std::invalid_argument("Paralellogram need only 4 points");
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
        throw std::invalid_argument("Paralellogram has both pairs equivalence sides");
    }
    if (peaks.at(1) - peaks.at(0) != peaks.at(2) - peaks.at(3) || peaks.at(2) - peaks.at(1) != peaks.at(3) - peaks.at(0)){
        throw std::invalid_argument("Paralellogram sides has to be parallel");
    }
}

template<class T>
ParalellogramValidator<T>::ParalellogramValidator() = default;
