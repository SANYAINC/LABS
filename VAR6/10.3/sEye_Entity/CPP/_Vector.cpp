#include "../sEye_Entity_Vector.h"
#include <iostream>

#define PATH_TO_DATA "../VAR6/10.3/data.bin"


entityVector::entityVector() {
    mVector = new entity* [SIZE_INIT];
    for (int i = 0; i < SIZE_INIT; ++i) {
        mVector[i] = nullptr;
    }
    mCapacity = SIZE_INIT;
    mSize = 0;

    if (!load()) {
        std::cerr << "CANT LOAD" << std::endl;
    }
}

entityVector::entityVector(const int size) {
    if (size < 0) {
        std::cerr << "INVALID SIZE: " << size << std::endl;
        exit(1007);
    }

    if (size == 0) {
        mVector = nullptr;
        mCapacity = 0;
        mSize = 0;
    } else {
        mVector = new entity*[size];
        for (int i = 0; i < size; ++i) {
            mVector[i] = nullptr;
        }
        mCapacity = size;
        mSize = 0;
    }
}

entityVector::entityVector(const entityVector& anotherVector) {
    int newCapacity = anotherVector.mCapacity;

    if (newCapacity == 0) {
        mVector = nullptr;
        mCapacity = 0;
        mSize = 0;
    } else {
        mVector = new entity* [newCapacity];
        mCapacity = newCapacity;
        mSize = anotherVector.mSize;
        for (int i = mSize; i < mCapacity; ++i) {
            mVector[i] = nullptr;
        }

        for (int i = 0; i < mSize; ++i) {
            entity* buffer = anotherVector.mVector[i];

            identifyAndPush(mVector, buffer, i);
        }

    }
}

entityVector::entityVector(entityVector&& anotherVector) {
    mVector = anotherVector.mVector;
    mCapacity = anotherVector.mCapacity;
    mSize = anotherVector.mSize;

    anotherVector.mVector = nullptr;
}

entityVector::~entityVector() {
    save();
    for (int i = 0; i < mCapacity; ++i) {
        delete mVector[i];
    }
    delete[] mVector;
}

void entityVector::resize(const int newSize) {
    entity** newVector = new entity*[newSize];
    mCapacity = newSize;

    for (int i = 0; i < mCapacity; ++i) {
        if (i < mSize) {
            newVector[i] = mVector[i];
            mVector[i] = nullptr;
        } else {
            newVector[i] = nullptr;
        }
    }
    delete[] mVector;
    mVector = newVector;
}

void entityVector::identifyAndPush(entity** vector, entity* object, int index) {
    switch (object->type()) {
        case HUMAN_ID: {
            vector[index] = new human(*dynamic_cast<human*>(object));
            return;
        }
        case ITEM_ID: {
            vector[index] = new item(*dynamic_cast<item*>(object));
            return;
        }
        case BIKE_ID: {
            vector[index] = new bike(*dynamic_cast<bike*>(object));
            return;
        }
        case CYCLIST_ID: {
            vector[index] = new cyclist(*dynamic_cast<cyclist*>(object));
            return;
        }
        case CAR_ID: {
            vector[index] = new car(*dynamic_cast<car*>(object));
            return;
        }
    }
}

entityVector& entityVector::operator=(const entityVector& anotherVector) {
    if (this == &anotherVector) {
        return *this;
    }

    if (mCapacity < anotherVector.mCapacity) {
        for (int i = 0; i < mCapacity; ++i) {
            delete mVector[i];
        }
        delete[] mVector;

        mVector = new entity* [anotherVector.mCapacity];
        mCapacity = anotherVector.mCapacity;
        for (int i = mSize; i < mCapacity; ++i) {
            mVector[i] = nullptr;
        }
    } else {
        for (int i = 0; i < mSize; ++i) {
            delete mVector[i];
        }
    }

    mSize = anotherVector.mSize;

    for (int i = 0; i < mSize; ++i) {
        entity* buffer = anotherVector.mVector[i];

        identifyAndPush(mVector, buffer, i);
    }

    return *this;
}

entityVector& entityVector::operator=(entityVector&& anotherVector) {
    if (&anotherVector == this) {
        return *this;
    }

    clear();
    delete [] mVector;

    mVector = anotherVector.mVector;
    mCapacity = anotherVector.mCapacity;
    mSize = anotherVector.mSize;

    anotherVector.mVector = nullptr;

    return *this;
}

entity* entityVector::operator[](int position) {
    if (position < 0 or position >= mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    return mVector[position];
}

void entityVector::pushBack(entity& object) {
    if (mSize == mCapacity) {
        resize(mCapacity * 2);
    }

    entity* buffer = &object;

    identifyAndPush(mVector, buffer, mSize++);
}

void entityVector::pushAt(const int index, entity& object) {
    if (index < 0 or index > mSize) {
        std::cerr << "INVALID INDEX: " << index << std::endl;
        exit(1008);
    }

    if (index == mSize) {
        pushBack(object);
        return;
    }

    mCapacity = mSize == mCapacity ? mCapacity * 2 : mCapacity;
    entity** newVector = new entity*[mCapacity];

    mSize++;

    entity* buffer = &object;

    identifyAndPush(newVector, buffer, index);

    int i = 0;
    int j = 0;
    for (; i < mSize;) {
        if (i != index) {
            newVector[i] = mVector[j];
            mVector[j] = nullptr;
            ++i;
            ++j;
        } else {
            ++i;
        }
    }

    delete [] mVector;

    mVector = newVector;

}

void entityVector::removeAt(const int position) {
    if (position < 0 or position >= mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    if (mSize == 0) {
        return;
    }
    delete mVector[position];

    int i = position;
    for (; i + 1 != mCapacity; ++i) {
        mVector[i] = mVector[i + 1];
    }
    mVector[i] = nullptr;
    mSize--;

}

int entityVector::getSize() const {
    return mSize;
}

int entityVector::getCapacity() const {
    return mCapacity;
}

void entityVector::print() const {
    if (mSize) {
        std::cout << "[";
        for (int i = 0; i < mSize; ++i) {
            mVector[i]->print();
            if (i != mSize - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << "[ ]" << std::endl;
    }
}

void entityVector::clear() {
    for (int i = 0; i < mSize; ++i) {
        delete mVector[i];
        mVector[i] = nullptr;
    }
    mSize = 0;
}

bool entityVector::save() {
    std::ofstream fileO(PATH_TO_DATA, std::ios::binary);
    if (!fileO.is_open()) {
        std::cerr << "CAN'T SAVE DATA" << std::endl;
        return false;
    }
    for (int i = 0; i < mSize; ++i) {
        identifyAndSave(fileO, mVector[i]);
    }
    fileO.close();
    return true;
}

bool entityVector::load() {
    std::ifstream fileI(PATH_TO_DATA, std::ios::binary);
    if (!fileI.is_open()) {
        return false;
    }
    char type;

    fileI.seekg(0,std::ios::end);
    int eof = fileI.tellg();
    fileI.seekg(0, std::ios::beg);

    while (fileI.tellg() != eof) {
        type = readChar(fileI);

        short int xMin = readShort(fileI);
        short int xMax = readShort(fileI);
        short int yMin = readShort(fileI);
        short int yMax = readShort(fileI);

        switch (type) {
            case HUMAN_ID: {
                char sex = readChar(fileI);
                char adult = readChar(fileI);
                char glasses = readChar(fileI);
                char beard = readChar(fileI);

                human buffer(xMin, xMax, yMin, yMax, sex, adult, glasses, beard);
                pushBack(buffer);
                break;
            }
            case ITEM_ID: {
                const char* name = readString(fileI);
                const char* time = readString(fileI);

                item buffer(xMin, xMax, yMin, yMax, name, time);

                pushBack(buffer);

                delete [] name;
                delete [] time;

                break;
            }
            case BIKE_ID: {
                const char* color = readString(fileI);

                char lock = readChar(fileI);

                bike buffer(xMin, xMax, yMin, yMax, color, lock);
                pushBack(buffer);

                delete [] color;

                break;
            }
            case CYCLIST_ID: {
                char sex = readChar(fileI);
                char adult = readChar(fileI);
                char glasses = readChar(fileI);
                char beard = readChar(fileI);

                const char* color = readString(fileI);

                char lock = readChar(fileI);
                char helmet = readChar(fileI);

                cyclist buffer(xMin, xMax, yMin, yMax, sex, adult, glasses, beard, color, lock, helmet);
                pushBack(buffer);

                delete [] color;

                break;
            }
            case CAR_ID: {
                const char* color = readString(fileI);
                const char* plate = readString(fileI);

                char body = readChar(fileI);
                char taxi = readChar(fileI);

                car buffer(xMin, xMax, yMin, yMax, color, plate, body, taxi);
                pushBack(buffer);

                delete [] color;
                delete [] plate;

                break;
            }
        }
    }
    fileI.close();
    return true;
}

void entityVector::identifyAndSave(std::ofstream& fileO, entity* object) {
    char type = object->type();

    fileO.write(reinterpret_cast<char*>(&type), sizeof(char));

    writeShort(fileO, object->getXMin());
    writeShort(fileO, object->getXMax());
    writeShort(fileO, object->getYMin());
    writeShort(fileO, object->getYMax());

    switch (type) {
        case HUMAN_ID: {
            human* buf = dynamic_cast<human*>(object);
            writeChar(fileO, buf->getPersonSex());
            writeChar(fileO, buf->getPersonIsAdult());
            writeChar(fileO, buf->getPersonHasGlasses());
            writeChar(fileO, buf->getPersonHasBeard());

            return;
        }
        case ITEM_ID: {
            item* buf = dynamic_cast<item*>(object);
            writeString(fileO, buf->getItemName());
            writeString(fileO, buf->getItemTime());

            return;
        }
        case BIKE_ID: {
            bike* buf = dynamic_cast<bike*>(object);
            writeString(fileO, buf->getVehicleColor());
            writeChar(fileO, buf->getBikeLock());

            return;
        }
        case CYCLIST_ID: {
            human* bufferHuman = dynamic_cast<human*>(object);
            writeChar(fileO, bufferHuman->getPersonSex());
            writeChar(fileO, bufferHuman->getPersonIsAdult());
            writeChar(fileO, bufferHuman->getPersonHasGlasses());
            writeChar(fileO, bufferHuman->getPersonHasBeard());

            bike* bufferBike = dynamic_cast<bike*>(object);
            writeString(fileO, bufferBike->getVehicleColor());
            writeChar(fileO, bufferBike->getBikeLock());

            cyclist* bufferCyclist = dynamic_cast<cyclist*>(object);
            writeChar(fileO, bufferCyclist->getCyclistHasHelmet());

            return;
        }
        case CAR_ID: {
            car* buf = dynamic_cast<car*>(object);
            writeString(fileO, buf->getVehicleColor());
            writeString(fileO, buf->getMTRegisterPlate());
            writeChar(fileO, buf->getCarBodyType());
            writeChar(fileO, buf->getCarIsTaxi());

            return;
        }
    }
}

const char* entityVector::readString(std::ifstream& fileI) {
    int size;
    fileI.read(reinterpret_cast<char*>(&size), sizeof(int));
    char* string = new char[size+1];
    fileI.read(reinterpret_cast<char*>(string), sizeof(char)*(size+1));
    return string;
}

char entityVector::readChar(std::ifstream& fileI) {
    char buffer;
    fileI.read(reinterpret_cast<char*>(&buffer), sizeof(char));
    return buffer;
}

short entityVector::readShort(std::ifstream& fileI) {
    short buffer;
    fileI.read(reinterpret_cast<char*>(&buffer), sizeof(short));
    return buffer;
}

void entityVector::writeString(std::ofstream& fileO, const char* string) {
    int size = 0;
    for (;string[size]; ++size);
    char end = 0;
    fileO.write(reinterpret_cast<char*>(&size), sizeof(int));
    fileO.write(reinterpret_cast<const char*>(string), sizeof(char)*size);
    fileO.write(reinterpret_cast<char*>(&end), sizeof(char));
}

void entityVector::writeChar(std::ofstream& fileO, char character) {
    fileO.write(reinterpret_cast<char*>(&character), sizeof(char));
}

void entityVector::writeShort(std::ofstream& fileO, short number) {
    fileO.write(reinterpret_cast<char*>(&number), sizeof(short));
}

