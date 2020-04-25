#include "../sEye_Entity.h"

motorTransport::motorTransport(short int xMin, short int xMax, short int yMin, short int yMax, const char* VehicleColor,
                               const char* registerPlate)
                               : vehicle(xMin, xMax, yMin, yMax, VehicleColor) {

    validate(registerPlate);

    int plateSize = 0;
    for (; registerPlate[plateSize++];);
    int newSize = plateSize < MAX_CHAR ? plateSize : MAX_CHAR;

    mRegisterPlate = new char[newSize];

    int i = 0;
    while (i < newSize - 1) {
        mRegisterPlate[i] = registerPlate[i];
        ++i;
    }
    mRegisterPlate[i] = 0;
}

motorTransport::motorTransport(const motorTransport& anotherMT)
                              : vehicle(anotherMT.mXMin, anotherMT.mXMax, anotherMT.mYMin, anotherMT.mYMax, anotherMT.mColor) {
    int anotherPlateSize = 0;
    for (;anotherMT.mRegisterPlate[anotherPlateSize++];);

    mRegisterPlate = new char[anotherPlateSize];

    int i = 0;
    while (i < anotherPlateSize - 1) {
        mRegisterPlate[i] = anotherMT.mRegisterPlate[i];
        ++i;
    }
    mRegisterPlate[i] = 0;
}

motorTransport& motorTransport::operator=(const motorTransport& anotherMT) {
    if (this == &anotherMT) {
        return *this;
    }

    vehicle::operator=(anotherMT);

    int anotherPlateSize = 0;
    for (;anotherMT.mRegisterPlate[anotherPlateSize++];);
    int currentPlateSize = 0;
    for (;mRegisterPlate[currentPlateSize++];);

    if (currentPlateSize < anotherPlateSize) {
        delete [] mRegisterPlate;
        mRegisterPlate = new char[anotherPlateSize];
    }

    int i = 0;
    for (; i < anotherPlateSize - 1; ++i) {
        mRegisterPlate [i] = anotherMT.mRegisterPlate [i];
    }
    mRegisterPlate [i] = 0;

    return *this;
}

motorTransport::~motorTransport() {
    delete [] mRegisterPlate;
    //std::cout << "CALLED MT" << std::endl;
}

void motorTransport::validate(const char* registerPlate) {
    try {
        if (registerPlate[0] == 0) {
            throw "REGISTER PLATE VALUE IS EMPTY";
        }
    } catch (const char* errorMessage) {
        std::cerr << errorMessage << std::endl;
        exit(1003);
    }
}

const char* motorTransport::getMTRegisterPlate() const {
    return mRegisterPlate;
}

void motorTransport::setMTRegisterPlate(const char* registerPlate) {
    validate(registerPlate);

    int anotherPlateSize = 0;
    for (;registerPlate[anotherPlateSize++];);
    anotherPlateSize = anotherPlateSize < MAX_CHAR ? anotherPlateSize : MAX_CHAR;
    int currentPlateSize = 0;
    for (;mRegisterPlate[currentPlateSize++];);

    if (currentPlateSize < anotherPlateSize) {
        delete [] mRegisterPlate;
        mRegisterPlate = new char[anotherPlateSize];
    }

    int i = 0;
    for (; i < anotherPlateSize - 1; ++i) {
        mRegisterPlate [i] = registerPlate [i];
    }
    mRegisterPlate [i] = 0;
}
