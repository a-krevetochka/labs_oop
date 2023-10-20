//
// Created by meteo on 18.10.2023.
//

#include "BaseFigure.h"
#include "Rectangle.h"
#include "Rhomb.h"
#include "Trapezoid.h"

BaseFigure::BaseFigure() = default;

BaseFigure::BaseFigure(Vector<Point> peaks) {
    _peaks = peaks;
}

Point BaseFigure::centerOfRounding() {
    double sum_x = 0.0;
    double sum_y = 0.0;
    for (int index = 0; index < _peaks.size(); ++index) {
        sum_x += _peaks.at(index).getX();
        sum_y += _peaks.at(index).getY();
    }
    return *new Point(sum_x / (double) _peaks.size(), sum_y / (double) _peaks.size());
}

std::ostream &operator<<(std::ostream &out, BaseFigure * baseFigure) {
    for (int indexOfPeak = 0; indexOfPeak < baseFigure->_peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << baseFigure->_peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

