//
// Created by meteo on 18.10.2023.
//

#include "Rhomb.h"
#include "cmath"
template<class T>
Rhomb<T> &Rhomb<T>::operator=(const BaseFigure<T> &right) {
    if (const Rhomb pRhomb = *dynamic_cast<const Rhomb *>(&right)) {
        this->peaks = right.getPeaks();
    } else {
        throw std::exception();
    }
}

template<class T>
Rhomb<T>::operator double() const {
    double diagonal1 = sqrt(
            pow(this->_peaks.at(0).getX() - this->_peaks.at(2).getX(), 2) + pow(this->_peaks.at(0).getY() - this->_peaks.at(2).getY(), 2));
    double diagonal2 = sqrt(
            pow(this->_peaks.at(1).getX() - this->_peaks.at(3).getX(), 2) + pow(this->_peaks.at(1).getY() - this->_peaks.at(3).getY(), 2));
    return diagonal1 * diagonal2 / 2;
}

template<class T>
bool Rhomb<T>::operator==(const BaseFigure<T> &right) const {
    if (const Rhomb* pRhomb = dynamic_cast<const Rhomb*>(&right)){
        Point difference = this->_peaks.at(0) - pRhomb->_peaks.at(0);
        for (int indexOfPeak = 1; indexOfPeak < this->_peaks.size(); ++indexOfPeak) {
            Point currentDifference = this->_peaks.at(indexOfPeak) - pRhomb->_peaks.at(indexOfPeak);
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

template<class T>
Rhomb<T>::Rhomb(Vector<Point<T>> peaks) {
    this->_peaks = peaks;
}

template<class T>
Rhomb<T>::Rhomb() = default;

template<class T>
std::ostream &operator<<(std::ostream &out, const Rhomb<T> &rhomb) {
    std::cout << "Rhomb" << std::endl;
    for (int indexOfPeak = 0; indexOfPeak < rhomb._peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << rhomb._peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

template<class T>
std::istream operator>>(std::istream &in, Rhomb<T> &rhomb) {
    for (int indexOfPeak = 0; indexOfPeak < 4; ++indexOfPeak) {
        std::cout << "enter coordinates for peak: " << indexOfPeak << std::endl;
        Point<T> point;
        in >> point;
        rhomb._peaks.push_back(point);
    }
    FigureValidator<T>::Validate(typeid(Rhomb<T>), rhomb._peaks);
    return std::istream(nullptr);
}

template<class T>
void Rhomb<T>::setPeaks(Vector<Point<T>> peaks) {
    FigureValidator<T>::Validate(typeid(Rhomb), peaks);
    this->_peaks = peaks;
}

template<class T>
Rhomb<T> &Rhomb<T>::createFromPoints(Vector<Point<T>> peaks) {
    FigureValidator<T>::Validate(typeid(Rhomb), peaks);
    return *new Rhomb(peaks);
}

