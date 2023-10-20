//
// Created by meteo on 19.10.2023.
//

#include "FigureValidator.h"

Vector<IFigureValidator*> FigureValidator::_validators{new RectangleValidator, new RhombValidator, new TrapezoidValidator};

void FigureValidator::Validate(const std::type_info& typeInfo, Vector<Point> peaks) {
    for (int index = 0; index < FigureValidator::_validators.size(); ++index) {
        IFigureValidator* figureValidator = FigureValidator::_validators.at(index);

        if (figureValidator->isAllowedForType(typeInfo)){
            figureValidator->validateFigure(peaks);
        }
    }
}
