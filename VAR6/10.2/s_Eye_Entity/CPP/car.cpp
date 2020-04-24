#include "../sEye_Entity.h"

car::car(short int xMin, short int xMax, short int yMin, short int yMax, const char* vehicleColor, const char* registerPlate,
         char carBodyType, char isTaxi) : motorTransport(xMin, xMax, yMin, yMax, vehicleColor, registerPlate),
                                          entity(xMin, xMax, yMin, yMax) {
    validate(carBodyType, 'B');
    validate(isTaxi, 'T');

    mBodyType = carBodyType;
    mIsTaxi = isTaxi;

}

car::~car() {
    //std::cout << "CALLED CAR" << std::endl;
}

void car::validate(char param, char type) {
    try {
        if (type == 'T' and param != 'Y' and param != 'N' and param != 'U') {
            throw param;
        }
        if (type == 'B' and (param < 48 or param > 57)) {
            throw param;
        }
    } catch (char invalidParameter) {
        std::cerr << "INVALID PARAMETER VALUE. EXPECTED Y/N/U OR 0-10, RECEIVED " << invalidParameter << std::endl;
        exit(1006);
    }
}

char car::getCarBodyType() const {
    return mBodyType;
}

char car::getCarIsTaxi() const {
    return mIsTaxi;
}

void car::setCarBodyType(char bodyType) {
    validate(bodyType, 'B');

    mBodyType = bodyType;
}

void car::setCarIsTaxi(bool isTaxi) {
    validate(isTaxi, 'T');

    mIsTaxi = isTaxi;
}

void car::print() const {
    std::cout << "{ " << std::endl;
    std::cout << "   \"Object\": \"Car\", " << std::endl;
    std::cout << "   \"Properties\": {" << std::endl;
    std::cout << "      \"FrameArea\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "      \"Vehicle\": {" << std::endl;
    std::cout << "         \"Color\": " << "\"" << mColor <<"\"," << std::endl;
    std::cout << "         \"MotorTransport\": {" << std::endl;
    std::cout << "            \"RegisterPlate\":" << "\"" << mRegisterPlate <<"\"," << std::endl;
    std::cout << "            \"Car\": {" << std::endl;
    std::cout << "               \"IsTaxi\": " << "\"" << mIsTaxi <<"\"," << std::endl;
    std::cout << "               \"BodyType\": " << "\"" << mBodyType <<"\"" << std::endl;
    std::cout << "            }" << std::endl;
    std::cout << "         }" << std::endl;
    std::cout << "      }" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << "}" << std::endl;
}
