#include "../sEye_Entity.h"

human::human(short int xMin, short int xMax, short int yMin, short int yMax, char sex, char isAdult, char hasGlasses,
             char hasBeard) : entity(xMin, xMax, yMin, yMax) {

    validate(sex, 'S');
    validate(isAdult, 'B');
    validate(hasGlasses, 'B');
    validate(hasBeard, 'B');

    mSex = sex;
    mIsAdult = isAdult;
    mHasGlasses = hasGlasses;
    mHasBeard = hasBeard;
}

human::~human() {
    //std::cout << "CALLED HUMAN" << std::endl;
}

void human::validate(char param, char type) {
    try {
        if (type == 'S' and param != 'M' and param != 'F' and param != 'U') {
            throw param;
        }
        if (type == 'B' and param != 'Y' and param != 'N' and param != 'U') {
            throw param;
        }
    } catch (char invalidParameter) {
        std::cerr << "INVALID PARAMETER VALUE. EXPECTED Y/N/U OR M/F/U, RECEIVED " << invalidParameter << std::endl;
        exit(1002);
    }
}

char human::getPersonSex() const {
    return mSex;
}

char human::getPersonIsAdult() const {
    return mIsAdult;
}

char human::getPersonHasGlasses() const {
    return mHasGlasses;
}

char human::getPersonHasBeard() const {
    return mHasBeard;
}

void human::setPersonSex(char sex) {
    validate(sex, 'S');
    mSex = sex;
}

void human::setPersonIsAdult(char isAdult) {
    validate(isAdult, 'B');
    mIsAdult = isAdult;
}

void human::setPersonHasGlasses(char hasGlasses) {
    validate(hasGlasses, 'B');
    mHasGlasses = hasGlasses;
}

void human::setPersonHasBeard(char hasBeard) {
    validate(hasBeard, 'B');
    mHasBeard = hasBeard;
}

void human::print() const {
    std::cout << "{" << std::endl;
    std::cout << "   \"Object\": \"Human\", " << std::endl;
    std::cout << "   \"Properties\": {" << std::endl;
    std::cout << "      \"FrameArea\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "      \"Person\": {" << std::endl;
    std::cout << "         \"Sex\": " << "\"" << mSex <<"\"," << std::endl;
    std::cout << "         \"IsAdult\": " << "\"" << mIsAdult <<"\"," << std::endl;
    std::cout << "         \"HasGlasses\": " << "\"" << mHasGlasses <<"\"," << std::endl;
    std::cout << "         \"HasBeard\": " << "\"" << mHasBeard <<"\"" << std::endl;
    std::cout << "      }" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << "}" << std::endl;
}
