#include "../../Entities.h"

item::item(int xMin, int xMax, int yMin, int yMax,
           const char* itemName, const char* timeWhenAppeared) : entity(xMin, xMax, yMin, yMax) {

    validate(itemName);
    validate(timeWhenAppeared);

    int nameSize = 0;
    for (; itemName[nameSize++];);
    int timeSize = 0;
    for (;timeWhenAppeared[timeSize++];);

    int newNameSize = nameSize < MAX_CHAR ? nameSize : MAX_CHAR;
    int newTimeSize = timeSize < MAX_CHAR ? timeSize : MAX_CHAR;

    mName = new char[newNameSize];
    mFirstAppearanceTime = new char[newTimeSize];

    int i = 0;
    for (; i < newNameSize - 1; ++i) {
        mName[i] = itemName[i];
    }
    mName[i] = 0;

    i = 0;
    for (; i < newTimeSize - 1; ++i) {
        mFirstAppearanceTime[i] = timeWhenAppeared[i];
    }
    mFirstAppearanceTime[i] = 0;

}

item::item() {
    mFirstAppearanceTime = new char[2];
    mFirstAppearanceTime[0] = '?';
    mFirstAppearanceTime[1] = 0;

    mName = new char[2];
    mName[0] = '?';
    mName[1] = 0;
}

item::item(const item& anotherItem)
          : entity(anotherItem.mXMin, anotherItem.mXMax, anotherItem.mYMin, anotherItem.mYMax) {

    int anotherNameSize = 0;
    for (;anotherItem.mName[anotherNameSize++];);
    int anotherTimeSize = 0;
    for (;anotherItem.mFirstAppearanceTime[anotherTimeSize++];);

    mName = new char[anotherNameSize];
    mFirstAppearanceTime = new char[anotherTimeSize];

    int i = 0;
    while (i < anotherNameSize - 1) {
        mName[i] = anotherItem.mName[i];
        ++i;
    }
    mName[i] = 0;

    i = 0;
    while (i < anotherTimeSize - 1) {
        mFirstAppearanceTime[i] = anotherItem.mFirstAppearanceTime[i];
        ++i;
    }
    mFirstAppearanceTime[i] = 0;
}

item::~item() {
    delete [] mName;
    delete [] mFirstAppearanceTime;
    //std::cout << "CALLED ITEM" << std::endl;
}

void item::validate(const char* string) {
    try {
        if (string[0] == 0) {
            throw "ITEM NAME OR APPEARANCE TIME IS EMPTY";
        }
    } catch (const char* errorMessage) {
        std::cerr << errorMessage << std::endl;
        exit(1004);
    }
}

item& item::operator=(const item& anotherItem) {
    if (this == &anotherItem) {
        return *this;
    }

    entity::operator=(anotherItem);

    int anotherSize = 0;
    for (;anotherItem.mName[anotherSize++];);
    int currentSize = 0;
    for (;mName[currentSize++];);

    if (currentSize < anotherSize) {
        delete [] mName;
        mName = new char[anotherSize];
    }

    int i = 0;
    for (; i < anotherSize - 1; ++i) {
        mName[i] = anotherItem.mName[i];
    }
    mName[i] = 0;


    anotherSize = 0;
    for (;anotherItem.mFirstAppearanceTime[anotherSize++];);
    currentSize = 0;
    for (;mFirstAppearanceTime[currentSize++];);

    if (currentSize < anotherSize) {
        delete [] mFirstAppearanceTime;
        mFirstAppearanceTime = new char[anotherSize];
    }

    i = 0;
    for (; i < anotherSize - 1; ++i) {
        mFirstAppearanceTime[i] = anotherItem.mFirstAppearanceTime[i];
    }
    mFirstAppearanceTime[i] = 0;

    return *this;
}

const char* item::getItemName() const {
    return mName;
}

const char* item::getItemTime() const {
    return mFirstAppearanceTime;
}

void item::setItemName(const char* name) {
    validate(name);

    int anotherNameSize = 0;
    for (;name[anotherNameSize++];);
    anotherNameSize = anotherNameSize < MAX_CHAR ? anotherNameSize : MAX_CHAR;

    int currentNameSize = 0;
    for (;mName[currentNameSize++];);

    if (currentNameSize < anotherNameSize) {
        delete [] mName;
        mName = new char[anotherNameSize];
    }

    int i = 0;
    for (; i < anotherNameSize - 1; ++i) {
        mName[i] = name[i];
    }
    mName[i] = 0;
}

void item::setItemTime(const char* firstAppearanceTime) {
    validate(firstAppearanceTime);

    int anotherTimeSize = 0;
    for (;firstAppearanceTime[anotherTimeSize++];);
    anotherTimeSize = anotherTimeSize < MAX_CHAR ? anotherTimeSize : MAX_CHAR;

    int currentTimeSize = 0;
    for (;mFirstAppearanceTime[currentTimeSize++];);

    if (currentTimeSize < anotherTimeSize) {
        delete [] mFirstAppearanceTime;
        mFirstAppearanceTime = new char[anotherTimeSize];
    }

    int i = 0;
    for (; i < anotherTimeSize - 1; ++i) {
        mFirstAppearanceTime[i] = firstAppearanceTime[i];
    }
    mFirstAppearanceTime[i] = 0;
}

void item::print() const {
    std::cout << std::endl << "{" << std::endl;
    std::cout << "   \"Object\": \"Item\", " << std::endl;
    std::cout << "   \"Properties\": {" << std::endl;
    std::cout << "      \"FrameArea\": [[" << mXMin << ", " << mYMax << "], [" << mXMax << ", " << mYMin << "]]," << std::endl;
    std::cout << "      \"Item\": {" << std::endl;
    std::cout << "         \"Name\": " << "\"" << mName <<"\"," << std::endl;
    std::cout << "         \"FirstAppearedTime\": " << "\"" << mFirstAppearanceTime <<"\"" << std::endl;
    std::cout << "      }" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << "}" << std::endl;
}

char item::type() const {
    return ITEM_ID;
}

void item::write(std::ofstream& oFile) const {
    char type = ITEM_ID;
    oFile.write(reinterpret_cast<char*>(&type), sizeof(char));

    oFile.write(reinterpret_cast<const char*>(&mXMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mXMax), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMin), sizeof(int));
    oFile.write(reinterpret_cast<const char*>(&mYMax), sizeof(int));

    int sizeTimeStr = 0;
    for (; mFirstAppearanceTime[sizeTimeStr++];);
    oFile.write(reinterpret_cast<char*>(&sizeTimeStr), sizeof(int));
    oFile.write(reinterpret_cast<char*>(mFirstAppearanceTime), sizeof(char) * sizeTimeStr);

    int sizeNameStr = 0;
    for (;mName[sizeNameStr++];);
    oFile.write(reinterpret_cast<char*>(&sizeNameStr), sizeof(int));
    oFile.write(reinterpret_cast<char*>(mName), sizeof(char) * sizeNameStr);
}

void item::read(std::ifstream& iFile) {
    iFile.read(reinterpret_cast<char*>(&mXMin), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mXMax), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mYMin), sizeof(int));
    iFile.read(reinterpret_cast<char*>(&mYMax), sizeof(int));

    int sizeTimeStr;
    iFile.read(reinterpret_cast<char*>(&sizeTimeStr), sizeof(int));
    char* newTimeStr = new char[sizeTimeStr];
    iFile.read(reinterpret_cast<char*>(newTimeStr), sizeof(char) * sizeTimeStr);
    delete [] mFirstAppearanceTime;
    mFirstAppearanceTime = newTimeStr;

    int sizeNameStr;
    iFile.read(reinterpret_cast<char*>(&sizeNameStr), sizeof(int));
    char* newNameStr = new char[sizeNameStr];
    iFile.read(reinterpret_cast<char*>(newNameStr), sizeof(char) * sizeNameStr);
    delete [] mName;
    mName = newNameStr;
}
