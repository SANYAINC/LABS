#include "../sEye_Entity.h"

cyclist::cyclist(short int xMin, short int xMax, short int yMin, short int yMax, char sex, char isAdult,
                 char hasGlasses, char hasBeard, const char* color, char hasLock, char hasHelmet)
                 : human(xMin, xMax, yMin, yMax, sex, isAdult, hasGlasses, hasBeard),
                   bike(xMin, xMax, yMin, yMax, color, hasLock),
                   entity(xMin, xMax, yMin, yMax) {

    validate(hasHelmet);

    mHasHelmet = hasHelmet;
}

cyclist::~cyclist() {
    //std::cout << "CALLED CYCLIST" << std::endl;
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

char cyclist::getCyclistHasHelmet() const {
    return mHasHelmet;
}

void cyclist::setCyclistHasHelmet(char hasHelmet) {
    validate(hasHelmet);

    mHasHelmet = hasHelmet;
}

void cyclist::print() const {
    std::cout << "{ " << std::endl;
    std::cout << "   \"Object\": \"Cyclist\", " << std::endl;
    std::cout << "   \"Properties\": {" << std::endl;
    std::cout << "      \"FrameArea\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "      \"Vehicle\": {" << std::endl;
    std::cout << "         \"Color\": " << "\"" << mColor <<"\"," << std::endl;
    std::cout << "         \"Bike\": {" << std::endl;
    std::cout << "            \"HasLock\":" << "\"" << mHasLock <<"\"" << std::endl;
    std::cout << "         }" << std::endl;
    std::cout << "      }," << std::endl;
    std::cout << "      \"Person\": {" << std::endl;
    std::cout << "         \"Sex\": " << "\"" << mSex <<"\"," << std::endl;
    std::cout << "         \"IsAdult\": " << "\"" << mIsAdult <<"\"," << std::endl;
    std::cout << "         \"HasGlasses\": " << "\"" << mHasGlasses <<"\"," << std::endl;
    std::cout << "         \"HasBeard\": " << "\"" << mHasBeard <<"\"" << std::endl;
    std::cout << "      }" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << "}" << std::endl;
}
