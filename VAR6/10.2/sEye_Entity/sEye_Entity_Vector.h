#pragma once
#include "sEye_Entity.h"
#define SIZE_INIT 2


class entityVector {
    entity** mVector;
    int mCapacity;
    int mSize;

    void resize(int newSize);

    void identifyAndPushObject(entity** vector, entity* object, int index);

public:
    entityVector();
    entityVector(int size);
    entityVector(const entityVector& anotherVector);
    entityVector(entityVector&& anotherVector);
    ~entityVector();

    entityVector& operator=(const entityVector& anotherVector);
    entityVector& operator=(entityVector&& anotherVector);

    entity* operator[](int position);

    void pushBack(entity& object);

    void pushAt(int index, entity& object);

    void removeAt(int position);

    int getSize() const;

    int getCapacity() const;

    void print() const;

    void clear();
};