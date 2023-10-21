//
// Created by meteo on 18.10.2023.
//

#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle() = default;

Rectangle::Rectangle(Vector<Point> peaks){
    _peaks = peaks;
}

BaseFigure &Rectangle::operator=(const BaseFigure &right) {
    if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(&right)){
        _peaks = right.getPeaks();
    } else{
        throw std::exception();
    }
}

bool Rectangle::operator==(const BaseFigure &right) const {
    if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(&right)){
        Point difference = _peaks.at(0) - rectangle->_peaks.at(0);
        for (int indexOfPeak = 1; indexOfPeak < _peaks.size(); ++indexOfPeak) {
            Point currentDifference = _peaks.at(indexOfPeak) - rectangle->_peaks.at(indexOfPeak);
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

Rectangle::operator double() const {
    Point firstSide = _peaks.at(0) - _peaks.at(1);
    Point secondSide = _peaks.at(1) - _peaks.at(2);
    double area = sqrt(pow(firstSide.getX(), 2) + pow(firstSide.getY(), 2)) * sqrt(pow(secondSide.getX(), 2) + pow(secondSide.getY(), 2));
    return area;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &rectangle) {
    std::cout << "Rectangle" << std::endl;
    for (int indexOfPeak = 0; indexOfPeak < rectangle._peaks.size(); ++indexOfPeak) {
        out << "peak: " << indexOfPeak << " {" << rectangle._peaks.at(indexOfPeak) << "}" << std::endl;
    }
    return out;
}

std::istream operator>>(std::istream &in, Rectangle &rectangle) {
    for (int indexOfPeak = 0; indexOfPeak < 4; ++indexOfPeak) {
        std::cout << "enter coordinates for peak: " << indexOfPeak << std::endl;
        Point point;
        in >> point;
        rectangle._peaks.push_back(point);
    }
    FigureValidator::Validate(typeid(Rectangle), rectangle._peaks);
    return std::istream(nullptr);
}

void Rectangle::setPeaks(Vector<Point> peaks) {
    FigureValidator::Validate(typeid(Rectangle), peaks);
    _peaks = peaks;
}

Rectangle& Rectangle::createFromPoints(Vector<Point> peaks) {
    FigureValidator::Validate(typeid(Rectangle), peaks);
    Rectangle rectangle(peaks);
    return rectangle;
}



