#include "../sEye_Entity.h"

bike::bike(short int xMin, short int xMax, short int yMin, short int yMax, const char* vehicleColor, char bikeHasLock)
          : vehicle(xMin, xMax, yMin, yMax, vehicleColor), entity(xMin, xMax, yMin, yMax) {

    validate(bikeHasLock);

    mHasLock = bikeHasLock;
}

bike::~bike() {
    //std::cout << "CALLED BIKE" << std::endl;
}

void bike::validate(char param) {
    try {
        if (param != 'Y' and param != 'N' and param != 'U') {
            throw param;
        }
    } catch (char invalidParameter) {
        std::cerr << "INVALID PARAMETER VALUE. EXPECTED Y/N/U, RECEIVED " << invalidParameter << std::endl;
        exit(1002);
    }
}

char bike::getBikeLock() const {
    return mHasLock;
}

void bike::setBikeLock(char hasLock) {
    validate(hasLock);

    mHasLock = hasLock;
}

void bike::print() const {
    std::cout << "{" << std::endl ;
    std::cout << "   \"Object\": \"Bike\", " << std::endl;
    std::cout << "   \"Properties\": {" << std::endl;
    std::cout << "      \"FrameArea\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "      \"Vehicle\": {" << std::endl;
    std::cout << "         \"Color\": " << "\"" << mColor <<"\"," << std::endl;
    std::cout << "         \"Bike\": {" << std::endl;
    std::cout << "            \"HasLock\":" << "\"" << mHasLock <<"\"" << std::endl;
    std::cout << "         }" << std::endl;
    std::cout << "      }" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << "}";
}
