#pragma once

#include "sEye_Entity.h"

class entityVector {
protected:
    entity** mVector;
    int mSize;

public:
    entityVector();
    entityVector(int size);
    entityVector(const entityVector& anotherVector);
    entityVector(entityVector&& anotherVector);
    virtual ~entityVector();

    entityVector& operator=(const entityVector& anotherVector);
    entityVector& operator=(entityVector&& anotherVector);

    void resize(int size);

    void pushBack(const entity& object);

    void pushAt(int index, entity& obj);

    void removeAt(int index);

    void print();

    void clear();
};