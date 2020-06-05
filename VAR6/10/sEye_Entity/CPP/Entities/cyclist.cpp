#include "../../Entities.h"

cyclist::cyclist(int xMin, int xMax, int yMin, int yMax, char sex, char isAdult,
                 char hasGlasses, char hasBeard, const char* vehicleColor, char bikeHasLock, char cyclistHasHelmet)
                 : human(xMin, xMax, yMin, yMax, sex, isAdult, hasGlasses, hasBeard),
                   bike(xMin, xMax, yMin, yMax, vehicleColor, bikeHasLock),
                   entity(xMin, xMax, yMin, yMax) {

    validate(cyclistHasHelmet);

    mHasHelmet = cyclistHasHelmet;
}

cyclist::cyclist() {
    mHasHelmet = 'U';
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
    std::cout << std::endl << "{" << std::endl;
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

char cyclist::type() const {
    return CYCLIST_ID;
}

void cyclist::write(std::ofstream& oFile) const {
    char type = CYCLIST_ID;
    oFile.write(reinterpret_cast<char*>(&type), sizeof(char));

    oFile.write(reinterpret_cast<const char*>(&mXMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mXMax), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMax), sizeof(int));

    int sizeColorStr = 0;
    for (;mColor[sizeColorStr++];);
    oFile.write(reinterpret_cast<char*>(&sizeColorStr), sizeof(int));
    oFile.write(reinterpret_cast<char*>(mColor), sizeof(char) * sizeColorStr);

    oFile.write(reinterpret_cast<const char*>(&mHasLock), sizeof(char));

    oFile.write(reinterpret_cast<const char*>(&mSex), sizeof(char));
    oFile.write(reinterpret_cast<const char*>(&mIsAdult), sizeof(char));
    oFile.write(reinterpret_cast<const char*>(&mHasGlasses), sizeof(char));
    oFile.write(reinterpret_cast<const char*>(&mHasBeard), sizeof(char));

    oFile.write(reinterpret_cast<const char*>(&mHasHelmet), sizeof(char));
}

void cyclist::read(std::ifstream& iFile) {
    iFile.read(reinterpret_cast<char*>(&mXMin), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mXMax), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mYMin), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mYMax), sizeof(int));

    int sizeColorStr;
    iFile.read(reinterpret_cast<char*>(&sizeColorStr), sizeof(int));
    char* newColorStr = new char[sizeColorStr];
    iFile.read(reinterpret_cast<char*>(newColorStr), sizeof(char) * sizeColorStr);
    delete [] mColor;
    mColor = newColorStr;

    iFile.read(reinterpret_cast<char*>(&mHasLock), sizeof(char));

    iFile.read(reinterpret_cast<char*>(&mSex), sizeof(char));
    iFile.read(reinterpret_cast<char*>(&mIsAdult), sizeof(char));
    iFile.read(reinterpret_cast<char*>(&mHasGlasses), sizeof(char));
    iFile.read(reinterpret_cast<char*>(&mHasBeard), sizeof(char));

    iFile.read(reinterpret_cast<char*>(&mHasHelmet), sizeof(char));
}
