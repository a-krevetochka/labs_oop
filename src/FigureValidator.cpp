//
// Created by meteo on 19.10.2023.
//

#include "FigureValidator.h"
template<class T>
Vector<IFigureValidator<T>> FigureValidator<T>::_validators{*new RectangleValidator<T>, *new RhombValidator<T>, *new TrapezoidValidator<T>};

template<class T>
void FigureValidator<T>::Validate(const std::type_info& typeInfo, Vector<Point<T>> peaks) {
    for (int index = 0; index < FigureValidator::_validators.size(); ++index) {
        IFigureValidator<T>* figureValidator = FigureValidator::_validators.at(index);

        if (figureValidator->isAllowedForType(typeInfo)){
            figureValidator->validateFigure(peaks);
        }
    }
}
