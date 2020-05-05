#include "../../Entities.h"

car::car(int xMin, int xMax, int yMin, int yMax, const char* vehicleColor, const char* registerPlate,
         char carBodyType, char isTaxi) : motorTransport(xMin, xMax, yMin, yMax, vehicleColor, registerPlate),
                                          entity(xMin, xMax, yMin, yMax) {
    validate(carBodyType, 'B');
    validate(isTaxi, 'T');

    mBodyType = carBodyType;
    mIsTaxi = isTaxi;

}

car::car() {
    mBodyType = '0';
    mIsTaxi = 'U';
}

car::~car() {
    //std::cout << "CALLED CAR" << std::endl;
}

void car::validate(char param, char type) {
    try {
        if (type == 'T' and param != 'Y' and param != 'N' and param != 'U') {
            throw param;
        }
        if (type == 'B' and (param < 48 or param > 57)) {
            throw param;
        }
    } catch (char invalidParameter) {
        std::cerr << "INVALID PARAMETER VALUE. EXPECTED Y/N/U OR 0-10, RECEIVED " << invalidParameter << std::endl;
        exit(1006);
    }
}

char car::getCarBodyType() const {
    return mBodyType;
}

char car::getCarIsTaxi() const {
    return mIsTaxi;
}

void car::setCarBodyType(char bodyType) {
    validate(bodyType, 'B');

    mBodyType = bodyType;
}

void car::setCarIsTaxi(bool isTaxi) {
    validate(isTaxi, 'T');

    mIsTaxi = isTaxi;
}

void car::print() const {
    std::cout << std::endl << "{" << std::endl;
    std::cout << "   \"Object\": \"Car\", " << std::endl;
    std::cout << "   \"Properties\": {" << std::endl;
    std::cout << "      \"FrameArea\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "      \"Vehicle\": {" << std::endl;
    std::cout << "         \"Color\": " << "\"" << mColor <<"\"," << std::endl;
    std::cout << "         \"MotorTransport\": {" << std::endl;
    std::cout << "            \"RegisterPlate\":" << "\"" << mRegisterPlate <<"\"," << std::endl;
    std::cout << "            \"Car\": {" << std::endl;
    std::cout << "               \"IsTaxi\": " << "\"" << mIsTaxi <<"\"," << std::endl;
    std::cout << "               \"BodyType\": " << "\"" << mBodyType <<"\"" << std::endl;
    std::cout << "            }" << std::endl;
    std::cout << "         }" << std::endl;
    std::cout << "      }" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << "}" << std::endl;
}

char car::type() const {
    return CAR_ID;
}

void car::write(std::ofstream& oFile) const {
    char type = CAR_ID;
    oFile.write(reinterpret_cast<char*>(&type), sizeof(char));

    oFile.write(reinterpret_cast<const char*>(&mXMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mXMax), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMax), sizeof(int));

    int sizeColorStr = 0;
    for (;mColor[sizeColorStr++];);
    oFile.write(reinterpret_cast<char*>(&sizeColorStr), sizeof(int));
    oFile.write(reinterpret_cast<char*>(mColor), sizeof(char) * sizeColorStr);

    int sizePlateStr = 0;
    for (;mRegisterPlate[sizePlateStr++];);
    oFile.write(reinterpret_cast<char*>(&sizePlateStr), sizeof(int));
    oFile.write(reinterpret_cast<char*>(mRegisterPlate), sizeof(char) * sizePlateStr);

    oFile.write(reinterpret_cast<const char*>(&mBodyType), sizeof(char));
    oFile.write(reinterpret_cast<const char*>(&mIsTaxi), sizeof(char));
}

void car::read(std::ifstream& iFile) {
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

    int sizePlateStr = 0;
    iFile.read(reinterpret_cast<char*>(&sizePlateStr), sizeof(int));
    char* newPlateStr = new char[sizePlateStr];
    iFile.read(reinterpret_cast<char*>(newPlateStr), sizeof(char) * sizePlateStr);
    delete [] mRegisterPlate;
    mRegisterPlate = newPlateStr;

    iFile.read(reinterpret_cast<char*>(&mBodyType), sizeof(char));
    iFile.read(reinterpret_cast<char*>(&mIsTaxi), sizeof(char));
}
