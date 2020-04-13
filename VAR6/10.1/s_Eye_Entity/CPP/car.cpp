#include "../sEye_Entity.h"

car::car(short int xMin, short int xMax, short int yMin, short int yMax, const char* color, const char* registerPlate,
         char bodyType, char isTaxi) : motorTransport(xMin, xMax, yMin, yMax, color, registerPlate),
                                        entity(xMin, xMax, yMin, yMax) {
    validate(bodyType, 'B');
    validate(isTaxi, 'T');

    mBodyType = bodyType;
    mIsTaxi = isTaxi;

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

char car::getBodyType() const {
    return mBodyType;
}

char car::getTaxi() const {
    return mIsTaxi;
}

void car::setBodyType(char bodyType) {
    validate(bodyType, 'B');

    mBodyType = bodyType;
}

void car::setTaxi(bool isTaxi) {
    validate(isTaxi, 'T');

    mIsTaxi = isTaxi;
}

void car::print() const {
    std::cout << "{ " << "\"Obj\":" << std::endl;
    std::cout << "\t\"Frame area\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "\t\"Vehicle\": {" << std::endl;
    std::cout << "\t\t\"Color\": " << "\"" << mColor <<"\"," << std::endl;
    std::cout << "\t\t\"MotorTransport\": {" << std::endl;
    std::cout << "\t\t\t\"RegisterPlate\":" << "\"" << mRegisterPlate <<"\"," << std::endl;
    std::cout << "\t\t\t\"Car\": {" << std::endl;
    std::cout << "\t\t\t\t\"IsTaxi\": " << "\"" << mIsTaxi <<"\"," << std::endl;
    std::cout << "\t\t\t\t\"BodyType\": " << "\"" << mBodyType <<"\"" << std::endl;
    std::cout << "\t\t\t}" << std::endl;
    std::cout << "\t\t}" << std::endl;
    std::cout << "\t}" << std::endl;
    std::cout << "}" << std::endl;
}
