//
// Created by meteo on 18.10.2023.
//

#include "Trapezoid.h"
#include "cmath"
template<class T>
Trapezoid<T>::Trapezoid() = default;

template<class T>
bool Trapezoid<T>::operator==(const BaseFigure<T> &right) const {
    if (const Trapezoid* pTrapezoid = dynamic_cast<const Trapezoid*>(&right)){
        Point difference = this->_peaks.at(0) - pTrapezoid->_peaks.at(0);
        for (int indexOfPeak = 1; indexOfPeak < this->_peaks.size(); ++indexOfPeak) {
            Point currentDifference = this->_peaks.at(indexOfPeak) - pTrapezoid->_peaks.at(indexOfPeak);
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
Trapezoid<T>::Trapezoid(Vector<Point<T>> peaks){
    this->_peaks = peaks;
}

template<class T>
BaseFigure<T> &Trapezoid<T>::operator=(const BaseFigure<T> &right) {
    if (const Trapezoid* trapezoid = dynamic_cast<const Trapezoid*>(&right)){
        this->_peaks = right.getPeaks();
    } else{
        throw std::exception();
    }
}

template<class T>
std::ostream &operator<<(std::ostream &out, const Trapezoid<T> &trapezoid) {
    std::cout << "Trapezoid" << std::endl;
    for (int indexOfPeak = 0; indexOfPeak < trapezoid._peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << trapezoid._peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

template<class T>
std::istream operator>>(std::istream &in, Trapezoid<T> &trapezoid) {
    for (int indexOfPeak = 0; indexOfPeak < 4; ++indexOfPeak) {
        std::cout << "enter coordinates for peak: " << indexOfPeak << std::endl;
        Point<T> point;
        in >> point;
        trapezoid._peaks.push_back(point);
    }
    FigureValidator<T>::Validate(typeid(Trapezoid<T>), trapezoid._peaks);
    return std::istream(nullptr);
}

template<class T>
Trapezoid<T>::operator double() const {
    double footing1 = std::sqrt(
            pow(this->_peaks.at(1).getX() - this->_peaks.at(2).getX(), 2) +
            pow(this->_peaks.at(1).getY() - this->_peaks.at(2).getY(), 2)
    );

    double footing2 = std::sqrt(
            pow(this->_peaks.at(3).getX() - this->_peaks.at(0).getX(), 2) +
            pow(this->_peaks.at(3).getY() - this->_peaks.at(0).getY(), 2)
    );

    double height = std::abs(this->_peaks.at(0).getY() - this->_peaks.at(1).getY());

    return (footing1 + footing2) / 2 * height;
}

template<class T>
void Trapezoid<T>::setPeaks(Vector<Point<T>> peaks) {
    FigureValidator<T>::Validate(typeid(Trapezoid), peaks);
    this->_peaks = peaks;
}

template<class T>
Trapezoid<T> &Trapezoid<T>::createFromPoints(Vector<Point<T>> peaks) {
    FigureValidator<T>::Validate(typeid(Trapezoid), peaks);
    return *new Trapezoid(peaks);
}
