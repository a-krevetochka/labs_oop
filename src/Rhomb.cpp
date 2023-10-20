//
// Created by meteo on 18.10.2023.
//

#include "Rhomb.h"
#include "cmath"

BaseFigure &Rhomb::operator=(const BaseFigure &right) {
    if (const Rhomb *pRhomb = dynamic_cast<const Rhomb *>(&right)) {
        _peaks = right.getPeaks();
    } else {
        throw std::exception();
    }
}

Rhomb::operator double() const {
    double diagonal1 = sqrt(
            pow(_peaks.at(0).getX() - _peaks.at(2).getX(), 2) + pow(_peaks.at(0).getY() - _peaks.at(2).getY(), 2));
    double diagonal2 = sqrt(
            pow(_peaks.at(1).getX() - _peaks.at(3).getX(), 2) + pow(_peaks.at(1).getY() - _peaks.at(3).getY(), 2));
    return diagonal1 * diagonal2 / 2;
}

bool Rhomb::operator==(const BaseFigure &right) const {
    if (const Rhomb* pRhomb = dynamic_cast<const Rhomb*>(&right)){
        Point difference = _peaks.at(0) - pRhomb->_peaks.at(0);
        for (int indexOfPeak = 1; indexOfPeak < _peaks.size(); ++indexOfPeak) {
            Point currentDifference = _peaks.at(indexOfPeak) - pRhomb->_peaks.at(indexOfPeak);
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

Rhomb::Rhomb(Vector<Point> peaks) {
    FigureValidator::Validate(typeid(Rhomb), peaks);
    _peaks = peaks;
}

Rhomb::Rhomb() = default;

std::ostream &operator<<(std::ostream &out, const Rhomb &rhomb) {
    std::cout << "Rhomb" << std::endl;
    for (int indexOfPeak = 0; indexOfPeak < rhomb._peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << rhomb._peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

std::istream operator>>(std::istream &in, Rhomb &rhomb) {
    for (int indexOfPeak = 0; indexOfPeak < 4; ++indexOfPeak) {
        std::cout << "enter coordinates for peak: " << indexOfPeak << std::endl;
        Point point;
        in >> point;
        rhomb._peaks.push_back(point);
    }
    FigureValidator::Validate(typeid(Rhomb), rhomb._peaks);
    return std::istream(nullptr);
}

void Rhomb::setPeaks(Vector<Point> peaks) {
    FigureValidator::Validate(typeid(Rhomb), peaks);
    _peaks = peaks;
}

