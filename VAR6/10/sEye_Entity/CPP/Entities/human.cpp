#include "../../Entities.h"

human::human(int xMin, int xMax, int yMin, int yMax, char sex, char isAdult, char hasGlasses,
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

human::human() {
    mSex = 'U';
    mIsAdult = 'U';
    mHasGlasses = 'U';
    mHasBeard = 'U';
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
    std::cout << std::endl << "{" << std::endl;
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

char human::type() const {
    return HUMAN_ID;
}

void human::write(std::ofstream& oFile) const {
    char type = HUMAN_ID;
    oFile.write(reinterpret_cast<char*>(&type), sizeof(char));

    oFile.write(reinterpret_cast<const char*>(&mXMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mXMax), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMax), sizeof(int));

    oFile.write(reinterpret_cast<const char*>(&mSex), sizeof(char));
    oFile.write(reinterpret_cast<const char*>(&mIsAdult), sizeof(char));
    oFile.write(reinterpret_cast<const char*>(&mHasGlasses), sizeof(char));
    oFile.write(reinterpret_cast<const char*>(&mHasBeard), sizeof(char));
}

void human::read(std::ifstream& iFile){
    iFile.read(reinterpret_cast<char*>(&mXMin), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mXMax), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mYMin), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mYMax), sizeof(int));

    iFile.read(reinterpret_cast<char*>(&mSex), sizeof(char));
    iFile.read(reinterpret_cast<char*>(&mIsAdult), sizeof(char));
    iFile.read(reinterpret_cast<char*>(&mHasGlasses), sizeof(char));
    iFile.read(reinterpret_cast<char*>(&mHasBeard), sizeof(char));
}
