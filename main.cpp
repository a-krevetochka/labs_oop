#include "BaseFigure.h"
#include "Rectangle.h"
#include "Rhomb.h"
#include "RectangleValidator.h"
#include "Trapezoid.h"
int main(){
    Rectangle rectangle = Rectangle::createFromPoints({Point(1,2)});
    Rhomb rhomb = Rhomb::createFromPoints({Point(1,2)});
}