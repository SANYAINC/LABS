#include <iostream>
#include "../../Containers.h"

vector::vector() {
    mVector = new entity* [VECTOR_SIZE_INIT];
    for (int i = 0; i < VECTOR_SIZE_INIT; ++i) {
        mVector[i] = nullptr;
    }
    mCapacity = VECTOR_SIZE_INIT;
    mSize = 0;
}

vector::vector(const int capacity) {
    if (capacity < 0) {
        std::cerr << "INVALID SIZE: " << capacity << std::endl;
        exit(1007);
    }

    if (capacity == 0) {
        mVector = nullptr;
        mCapacity = 0;
        mSize = 0;
    } else {
        mVector = new entity*[capacity];
        for (int i = 0; i < capacity; ++i) {
            mVector[i] = nullptr;
        }
        mCapacity = capacity;
        mSize = 0;
    }
}

vector::vector(const vector& anotherVector) {
    int newCapacity = anotherVector.mCapacity;

    if (newCapacity == 0) {
        mVector = nullptr;
        mCapacity = 0;
        mSize = 0;
    } else {
        mVector = new entity*[newCapacity];
        mCapacity = newCapacity;
        mSize = anotherVector.mSize;
        for (int i = 0; i < mSize; ++i) {
            entity* buffer = anotherVector.mVector[i];

            identifyAndPush(mVector, buffer, i);
        }
        for (int i = mSize; i < mCapacity; ++i) {
            mVector[i] = nullptr;
        }

    }
}

vector::vector(vector&& anotherVector) {
    mVector = anotherVector.mVector;
    mCapacity = anotherVector.mCapacity;
    mSize = anotherVector.mSize;

    anotherVector.mVector = nullptr;
}

vector::~vector() {
    for (int i = 0; i < mSize; ++i) {
        delete mVector[i];
    }
    delete[] mVector;
}

void vector::resize(const int newCapacity) {
    entity** newVector = new entity*[newCapacity];
    mCapacity = newCapacity;

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

void vector::identifyAndPush(entity** vector, entity* object, int index) {
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

vector& vector::operator=(const vector& anotherVector) {
    if (this == &anotherVector) {
        return *this;
    }

    for (int i = 0; i < mSize; ++i) {
        delete mVector[i];
        mVector[i] = nullptr;
    }

    mSize = anotherVector.mSize;

    if (mCapacity < anotherVector.mCapacity) {
        mCapacity = anotherVector.mCapacity;
        entity** newVector = new entity*[mCapacity];
        for (int i = mSize; i < mCapacity; ++i) {
            newVector[i] = nullptr;
        }
        mVector = newVector;
    }


    for (int i = 0; i < mSize; ++i) {
        entity* buffer = anotherVector.mVector[i];
        identifyAndPush(mVector, buffer, i);
    }

    return *this;
}

vector& vector::operator=(vector&& anotherVector) {
    if (&anotherVector == this) {
        return *this;
    }

    for (int i = 0; i < mSize; ++i) {
        delete [] mVector[i];
    }
    delete [] mVector;

    mVector = anotherVector.mVector;
    mCapacity = anotherVector.mCapacity;
    mSize = anotherVector.mSize;

    anotherVector.mVector = nullptr;
    mCapacity = 0;
    mSize = 0;

    return *this;
}

entity* vector::operator[](int position) const {
    if (position < 0 or position >= mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    return mVector[position];
}

void vector::print() const {
    for (int i = 0; i < mSize; ++i) {
        mVector[i]->print();
    }
}

void vector::pushBack(entity& object) {
    if (mSize == mCapacity) {
        resize(mCapacity * 2);
    }
    identifyAndPush(mVector, &object, mSize++);
}

void vector::pushAt(const int position, entity& object) {
    if (position < 0 or position > mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    if (position == mSize) {
        pushBack(object);
        return;
    }

    if (mSize == mCapacity) {
        mCapacity *= 2;
        entity** newVector = new entity*[mCapacity];
        for (int i = 0; i < mCapacity; ++i) {
            if (i < position) {
                newVector[i] = mVector[i];
            }
            if (i > position and i < mSize + 1) {
                newVector[i] = mVector[i - 1];
            }
            if (i >= mSize + 1) {
                newVector[i] = nullptr;
            }
        }
        delete [] mVector;
        mVector = newVector;
    } else {
        for (int i = mSize - 1; i >= position; --i) {
            mVector[i + 1] = mVector[i];
        }
    }
    mSize++;
    identifyAndPush(mVector, &object, position);
}

void vector::removeAt(const int position) {
    if (position < 0 or position >= mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    delete mVector[position];

    for (int i = position + 1; i < mSize; ++i) {
        mVector[i - 1] = mVector[i];
    }
    mVector[mSize-1] = nullptr;
    mSize--;
}

int vector::getSize() const {
    return mSize;
}

int vector::getCapacity() const {
    return mCapacity;
}

void vector::clear() {
    for (int i = 0; i < mSize; ++i) {
        delete mVector[i];
        mVector[i] = nullptr;
    }
    mSize = 0;
}