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
    std::cout << "CALLED HUMAN" << std::endl;
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

char human::getSex() const {
    return mSex;
}

char human::getAge() const {
    return mIsAdult;
}

char human::getGlasses() const {
    return mHasGlasses;
}

char human::getBeard() const {
    return mHasBeard;
}

void human::setSex(char sex) {
    validate(sex, 'S');
    mSex = sex;
}

void human::setAge(char isAdult) {
    validate(isAdult, 'B');
    mIsAdult = isAdult;
}

void human::setGlasses(char hasGlasses) {
    validate(hasGlasses, 'B');
    mHasGlasses = hasGlasses;
}

void human::setBeard(char hasBeard) {
    validate(hasBeard, 'B');
    mHasBeard = hasBeard;
}

void human::print() const {
    std::cout << "{" << std::endl << "\"Obj\":" << std::endl;
    std::cout << "\t\"Frame area\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "\t\"Person\": {" << std::endl;
    std::cout << "\t\t\"Sex\": " << "\"" << mSex <<"\"," << std::endl;
    std::cout << "\t\t\"IsAdult\": " << "\"" << mIsAdult <<"\"," << std::endl;
    std::cout << "\t\t\"HasGlasses\": " << "\"" << mHasGlasses <<"\"," << std::endl;
    std::cout << "\t\t\"HasBeard\": " << "\"" << mHasBeard <<"\"" << std::endl;
    std::cout << "\t}" << std::endl;
    std::cout << "}" << std::endl;
}
