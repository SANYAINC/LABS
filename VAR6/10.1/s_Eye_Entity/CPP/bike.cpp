#include "../sEye_Entity.h"

bike::bike(short int xMin, short int xMax, short int yMin, short int yMax, const char* color, char hasLock)
          : vehicle(xMin, xMax, yMin, yMax, color), entity(xMin, xMax, yMin, yMax) {

    validate(hasLock);

    mHasLock = hasLock;
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

char bike::getLock() const {
    return mHasLock;
}

void bike::setLock(char hasLock) {
    validate(hasLock);

    mHasLock = hasLock;
}

void bike::print() const {
    std::cout << "{ " << "\"Obj\":" << std::endl;
    std::cout << "\t\"Frame area\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "\t\"Vehicle\": {" << std::endl;
    std::cout << "\t\t\"Color\": " << "\"" << mColor <<"\"," << std::endl;
    std::cout << "\t\t\"Bike\": {" << std::endl;
    std::cout << "\t\t\t\"HasLock\":" << "\"" << mHasLock <<"\"" << std::endl;
    std::cout << "\t\t}" << std::endl;
    std::cout << "\t}" << std::endl;
    std::cout << "}" << std::endl;
}
