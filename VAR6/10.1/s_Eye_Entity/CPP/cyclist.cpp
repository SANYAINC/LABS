#include "../sEye_Entity.h"

#include <iostream>

cyclist::cyclist(short int xMin, short int xMax, short int yMin, short int yMax, char sex, char isAdult,
                 char hasGlasses, char hasBeard, const char* color, char hasLock, char hasHelmet)
                 : human(xMin, xMax, yMin, yMax, sex, isAdult, hasGlasses, hasBeard),
                   bike(xMin, xMax, yMin, yMax, color, hasLock),
                   entity(xMin, xMax, yMin, yMax) {

    validate(hasHelmet);

    mHasHelmet = hasHelmet;
}

void cyclist::validate(char param) {
    try {
        if (param != 'Y' and param != 'N' and param != 'U') {
            throw param;
        }
    } catch (char invalidParameter) {
        std::cerr << "INVALID PARAMETER VALUE. EXPECTED Y/N/U OR M/F/U, RECEIVED " << invalidParameter << std::endl;
        exit(1002);
    }
}

char cyclist::getHelmet() const {
    return mHasHelmet;
}

void cyclist::setHelmet(char hasHelmet) {
    validate(hasHelmet);

    mHasHelmet = hasHelmet;
}

void cyclist::print() const {
    std::cout << "{ " << "\"Obj\":" << std::endl;
    std::cout << "\t\"Frame area\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "\t\"Vehicle\": {" << std::endl;
    std::cout << "\t\t\"Color\": " << "\"" << mColor <<"\"," << std::endl;
    std::cout << "\t\t\"Bike\": {" << std::endl;
    std::cout << "\t\t\t\"HasLock\":" << "\"" << mHasLock <<"\"" << std::endl;
    std::cout << "\t\t}" << std::endl;
    std::cout << "\t}," << std::endl;
    std::cout << "\t\"Person\": {" << std::endl;
    std::cout << "\t\t\"Sex\": " << "\"" << mSex <<"\"," << std::endl;
    std::cout << "\t\t\"IsAdult\": " << "\"" << mIsAdult <<"\"," << std::endl;
    std::cout << "\t\t\"HasGlasses\": " << "\"" << mHasGlasses <<"\"," << std::endl;
    std::cout << "\t\t\"HasBeard\": " << "\"" << mHasBeard <<"\"" << std::endl;
    std::cout << "\t}" << std::endl;
    std::cout << "}" << std::endl;
}
