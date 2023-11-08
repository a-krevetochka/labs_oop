//
// Created by meteo on 18.10.2023.
//

#include "BaseFigure.h"
#include "Rectangle.h"
#include "Rhomb.h"
#include "Trapezoid.h"

template<class T>
BaseFigure<T>::BaseFigure() = default;

template<class T>
BaseFigure<T>::BaseFigure(Vector<Point<T>> peaks) {
    _peaks = peaks;
}

template<class T>
Point<T> BaseFigure<T>::centerOfRounding() {
    double sum_x = 0.0;
    double sum_y = 0.0;
    for (int index = 0; index < _peaks.size(); ++index) {
        sum_x += _peaks.at(index).getX();
        sum_y += _peaks.at(index).getY();
    }
    return *new Point(sum_x / (double) _peaks.size(), sum_y / (double) _peaks.size());
}

template<class T>
std::ostream &operator<<(std::ostream &out, BaseFigure<T>* baseFigure) {
    for (int indexOfPeak = 0; indexOfPeak < baseFigure->_peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << baseFigure->_peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

template<class T>
BaseFigure<T>::~BaseFigure() = default;

