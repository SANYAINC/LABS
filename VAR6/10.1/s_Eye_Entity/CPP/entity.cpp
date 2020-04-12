#include "../sEye_Entity.h"

#include <iostream>

entity::entity(short int xMin, short int xMax, short int yMin, short int yMax) {
    validate(xMin, xMax, 'X');
    validate(yMin, yMax, 'Y');

    mXMin = xMin;
    mXMax = xMax;
    mYMin = yMin;
    mYMax = yMax;
}

void entity::validate(short int min, short int max, char axis) {
    try {
        if (min >= max) {
            throw "MIN COORDINATE IS HIGHER THAN MAX";
        }
        if (min < 0 or max >= (axis == 'X' ? FRAME_WIDTH : FRAME_HEIGHT)) {
            throw "COORDINATES ARE OUT OF RANGE";
        }
    } catch (const char* errorMessage) {
        std::cerr << errorMessage << std::endl;
        exit(1001);
    }
}

short int entity::getXMin() const {
    return mXMin;
}

short int entity::getXMax() const {
    return mXMax;
}

short int entity::getYMin() const {
    return mYMin;
}

short int entity::getYMax() const {
    return mYMax;
}

void entity::setXRange(short int xMin, short int xMax) {
    validate(xMin, xMax, 'X');
    mXMin = xMin;
    mXMax = xMax;
}

void entity::setYRange(short int yMin, short int yMax) {
    validate(yMin, yMax, 'Y');
    mYMin = yMin;
    mYMax = yMax;
}
