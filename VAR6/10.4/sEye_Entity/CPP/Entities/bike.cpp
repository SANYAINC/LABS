#include "../../Entities.h"

bike::bike(int xMin, int xMax, int yMin, int yMax, const char* vehicleColor, char bikeHasLock)
          : vehicle(xMin, xMax, yMin, yMax, vehicleColor), entity(xMin, xMax, yMin, yMax) {

    validate(bikeHasLock);

    mHasLock = bikeHasLock;
}

bike::bike() {
    mHasLock = 'U';
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
    std::cout << std::endl << "{" << std::endl;
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
    std::cout << "}" << std::endl;
}

char bike::type() const {
    return BIKE_ID;
}

void bike::write(std::ofstream& oFile) const {
    char type = BIKE_ID;
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
}

void bike::read(std::ifstream& iFile) {
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
}
