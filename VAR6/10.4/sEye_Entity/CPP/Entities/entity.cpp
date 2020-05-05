#include "../../Entities.h"

entity::entity(int xMin, int xMax, int yMin, int yMax) {
    validate(xMin, xMax, 'X');
    validate(yMin, yMax, 'Y');

    mXMin = xMin;
    mXMax = xMax;
    mYMin = yMin;
    mYMax = yMax;
}

entity::entity() {
    mXMin = 0;
    mXMax = FRAME_WIDTH - 1;
    mYMin = 0;
    mYMax = FRAME_HEIGHT - 1;
}

entity::~entity() {
    //std::cout << "CALLED ENTITY" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const entity& obj) {
    obj.print();
    return out;
}

void entity::validate(int min, int max, char axis) {
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

int entity::getXMin() const {
    return mXMin;
}

int entity::getXMax() const {
    return mXMax;
}

int entity::getYMin() const {
    return mYMin;
}

int entity::getYMax() const {
    return mYMax;
}

void entity::setXRange(int xMin, int xMax) {
    validate(xMin, xMax, 'X');
    mXMin = xMin;
    mXMax = xMax;
}

void entity::setYRange(int yMin,int yMax) {
    validate(yMin, yMax, 'Y');
    mYMin = yMin;
    mYMax = yMax;
}
