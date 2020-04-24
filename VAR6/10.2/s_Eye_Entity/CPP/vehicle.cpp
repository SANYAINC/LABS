#include "../sEye_Entity.h"

vehicle::vehicle(short int xMin, short int xMax, short int yMin, short int yMax, const char* color)
                : entity(xMin, xMax, yMin, yMax) {

    validate(color);

    int colorSize = 0;
    for (; color[colorSize++];);
    int newSize = colorSize < MAX_CHAR ? colorSize : MAX_CHAR;

    mColor = new char[newSize];

    int i = 0;
    while (i < newSize - 1) {
        mColor[i] = color[i];
        ++i;
    }
    mColor[i] = 0;
}

vehicle::vehicle(const vehicle& anotherVehicle)
                : entity(anotherVehicle.mXMin, anotherVehicle.mXMax, anotherVehicle.mYMin, anotherVehicle.mYMax) {

    int anotherColorSize = 0;
    for (;anotherVehicle.mColor[anotherColorSize++];);

    mColor = new char[anotherColorSize];

    int i = 0;
    while (i < anotherColorSize - 1) {
        mColor[i] = anotherVehicle.mColor[i];
        ++i;
    }
    mColor[i] = 0;
}

vehicle& vehicle::operator=(const vehicle& anotherVehicle) {
    if (this == &anotherVehicle) {
        return *this;
    }

    entity::operator=(anotherVehicle);

    int anotherColorSize = 0;
    for (;anotherVehicle.mColor[anotherColorSize++];);
    int currentColorSize = 0;
    for (;mColor[currentColorSize++];);

    if (currentColorSize < anotherColorSize) {
        delete [] mColor;
        mColor = new char[anotherColorSize];
    }

    int i = 0;
    for (; i < anotherColorSize - 1; ++i) {
        mColor[i] = anotherVehicle.mColor[i];
    }
    mColor[i] = 0;

    return *this;
}

vehicle::~vehicle() {
    delete [] mColor;
    //std::cout << "CALLED VEHICLE" << std::endl;
}

void vehicle::validate(const char* color) {
    try {
        if (color[0] == 0) {
            throw "COLOR VALUE IS EMPTY";
        }
    } catch (const char* errorMessage) {
        std::cerr << errorMessage << std::endl;
        exit(1003);
    }
}

const char* vehicle::getVehicleColor() const {
    return mColor;
}

void vehicle::setVehicleColor(const char* color) {
    validate(color);

    int anotherColorSize = 0;
    for (;color[anotherColorSize++];);
    anotherColorSize = anotherColorSize < MAX_CHAR ? anotherColorSize : MAX_CHAR;
    int currentColorSize = 0;
    for (;mColor[currentColorSize++];);

    if (currentColorSize < anotherColorSize) {
        delete [] mColor;
        mColor = new char[anotherColorSize];
    }

    int i = 0;
    for (; i < anotherColorSize - 1; ++i) {
        mColor[i] = color[i];
    }
    mColor[i] = 0;
}
