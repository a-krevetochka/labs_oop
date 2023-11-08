//
// Created by meteo on 18.10.2023.
//

#include "Rectangle.h"
#include <cmath>

template<class T>
Rectangle<T>::Rectangle() = default;

template<class T>
Rectangle<T>::Rectangle(Vector<Point<T>> peaks){
    this->_peaks = peaks;
}

template<class T>
Paralellogram<T> &Rectangle<T>::operator=(const BaseFigure<T> &right) {
    if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(&right)){
        this->_peaks = right.getPeaks();
    } else{
        throw std::exception();
    }
}

template<class T>
bool Rectangle<T>::operator==(const BaseFigure<T> &right) const {
    if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(&right)){
        Point difference = this->_peaks.at(0) - rectangle->_peaks.at(0);
        for (int indexOfPeak = 1; indexOfPeak < this->_peaks.size(); ++indexOfPeak) {
            Point currentDifference = this->_peaks.at(indexOfPeak) - rectangle->_peaks.at(indexOfPeak);
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
Rectangle<T>::operator double() const {
    Point firstSide = this->_peaks.at(0) - this->_peaks.at(1);
    Point secondSide = this->_peaks.at(1) - this->_peaks.at(2);
    double area = sqrt(pow(firstSide.getX(), 2) + pow(firstSide.getY(), 2)) * sqrt(pow(secondSide.getX(), 2) + pow(secondSide.getY(), 2));
    return area;
}

template<class T>
std::ostream &operator<<(std::ostream &out, const Rectangle<T> &rectangle) {
    std::cout << "Rectangle" << std::endl;
    for (int indexOfPeak = 0; indexOfPeak < rectangle._peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << rectangle._peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

template<class T>
std::istream operator>>(std::istream &in, Rectangle<T> &rectangle) {
    for (int indexOfPeak = 0; indexOfPeak < 4; ++indexOfPeak) {
        std::cout << "enter coordinates for peak: " << indexOfPeak << std::endl;
        Point<T> point;
        in >> point;
        rectangle._peaks.push_back(point);
    }
    FigureValidator<T>::Validate(typeid(Rectangle<T>), rectangle._peaks);
    return std::istream(nullptr);
}

template<class T>
void Rectangle<T>::setPeaks(Vector<Point<T>> peaks) {
    FigureValidator<T>::Validate(typeid(Rectangle), peaks);
    this->_peaks = peaks;
}

template<class T>
Rectangle<T>& Rectangle<T>::createFromPoints(Vector<Point<T>> peaks) {
    FigureValidator<T>::Validate(typeid(Rectangle), peaks);
    Rectangle rectangle(peaks);
    return rectangle;
}



