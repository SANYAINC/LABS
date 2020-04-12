#include "../sEye_Entity.h"

#include <iostream>

human::human(short int xMin, short int xMax, short int yMin, short int yMax, char sex, char isAdult, char hasGlasses,
             char hasBeard) : entity(xMin, xMax, yMin, yMax) {

    validateSex(sex);
    validateParam(isAdult);
    validateParam(hasGlasses);
    validateParam(hasBeard);

    mSex = sex;
    mIsAdult = isAdult;
    mHasGlasses = hasGlasses;
    mHasBeard = hasBeard;
}

void human::validateSex(char sex) {
    try {
        if (sex != 'M' and sex != 'F' and sex != 'U') {
            throw sex;
        }
    } catch (char invalidSex) {
        std::cerr << "INVALID SEX: " << invalidSex << std::endl;
        exit(1002);
    }
}

void human::validateParam(char param) {
    try {
        if (param != 'Y' and param != 'N' and param != 'U') {
            throw param;
        }
    } catch (char invalidParam) {
        std::cerr << "INVALID PARAMETER VALUE. EXPECTED Y/N/U, RECEIVED " << param << std::endl;
        exit(1003);
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
    validateSex(sex);
    mSex = sex;
}

void human::setAge(char isAdult) {
    validateParam(isAdult);
    mIsAdult = isAdult;
}

void human::setGlasses(char hasGlasses) {
    validateParam(hasGlasses);
    mHasGlasses = hasGlasses;
}

void human::setBeard(char hasBeard) {
    validateParam(hasBeard);
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
