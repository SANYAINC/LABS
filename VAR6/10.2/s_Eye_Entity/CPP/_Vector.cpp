#include "../sEye_Entity_Vector.h"
#include <iostream>

entityVector::entityVector() {
    mVector = new entity* [SIZE_INIT];
    for (int i = 0; i < SIZE_INIT; ++i) {
        mVector[i] = nullptr;
    }
    mCapacity = SIZE_INIT;
    mSize = 0;
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

            identifyAndPushObject(mVector, buffer, i);
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

void entityVector::identifyAndPushObject(entity** vector, entity* object, int index) {

    if (dynamic_cast<cyclist*>(object)) {
        vector[index] = new cyclist(*dynamic_cast<cyclist*>(object));
        return;
    }
    if (dynamic_cast<car*>(object)) {
        vector[index] = new car(*dynamic_cast<car*>(object));
        return;
    }
    if (dynamic_cast<bike*>(object)) {
        vector[index] = new bike(*dynamic_cast<bike*>(object));
        return;
    }
    if (dynamic_cast<human*>(object)) {
        vector[index] = new human(*dynamic_cast<human*>(object));
        return;
    }
    if (dynamic_cast<item*>(object)) {
        vector[index] = new item(*dynamic_cast<item*>(object));
        return;
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

        identifyAndPushObject(mVector, buffer, i);
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

    identifyAndPushObject(mVector, buffer, mSize++);
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

    identifyAndPushObject(newVector, buffer, index);

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
