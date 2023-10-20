//
// Created by meteo on 18.10.2023.
//

#include "Trapezoid.h"
#include "cmath"

Trapezoid::Trapezoid() = default;

bool Trapezoid::operator==(const BaseFigure &right) const {
    if (const Trapezoid* pTrapezoid = dynamic_cast<const Trapezoid*>(&right)){
        Point difference = _peaks.at(0) - pTrapezoid->_peaks.at(0);
        for (int indexOfPeak = 1; indexOfPeak < _peaks.size(); ++indexOfPeak) {
            Point currentDifference = _peaks.at(indexOfPeak) - pTrapezoid->_peaks.at(indexOfPeak);
            if (!(currentDifference == difference)){
                return false;
            }
        }
        if (double (*this) != double (right)){
            return false;
        }
        return true;
    }
    return false;
}

Trapezoid::Trapezoid(Vector<Point> peaks){
    FigureValidator::Validate(typeid(Trapezoid), peaks);
    _peaks = peaks;
}

BaseFigure &Trapezoid::operator=(const BaseFigure &right) {
    if (const Trapezoid* trapezoid = dynamic_cast<const Trapezoid*>(&right)){
        _peaks = right.getPeaks();
    } else{
        throw std::exception();
    }
}

std::ostream &operator<<(std::ostream &out, const Trapezoid &trapezoid) {
    std::cout << "Trapezoid" << std::endl;
    for (int indexOfPeak = 0; indexOfPeak < trapezoid._peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << trapezoid._peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

std::istream operator>>(std::istream &in, Trapezoid &trapezoid) {
    for (int indexOfPeak = 0; indexOfPeak < 4; ++indexOfPeak) {
        std::cout << "enter coordinates for peak: " << indexOfPeak << std::endl;
        Point point;
        in >> point;
        trapezoid._peaks.push_back(point);
    }
    FigureValidator::Validate(typeid(Trapezoid), trapezoid._peaks);
    return std::istream(nullptr);
}

Trapezoid::operator double() const {
    double footing1 = std::sqrt(
            pow(_peaks.at(1).getX() - _peaks.at(2).getX(), 2) +
            pow(_peaks.at(1).getY() - _peaks.at(2).getY(), 2)
    );

    double footing2 = std::sqrt(
            pow(_peaks.at(3).getX() - _peaks.at(0).getX(), 2) +
            pow(_peaks.at(3).getY() - _peaks.at(0).getY(), 2)
    );

    double height = std::abs(_peaks.at(0).getY() - _peaks.at(1).getY());

    return (footing1 + footing2) / 2 * height;
}

void Trapezoid::setPeaks(Vector<Point> peaks) {
    FigureValidator::Validate(typeid(Trapezoid), peaks);
    _peaks = peaks;
}
