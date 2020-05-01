#pragma once
#include "sEye_Entity.h"
#include <fstream>
#define SIZE_INIT 2


class entityVector {
    entity** mVector;
    int mCapacity;
    int mSize;

    void resize(int newSize);

    void identifyAndPush(entity** vector, entity* object, int index);
    void identifyAndSave(std::ofstream& fileO, entity* object);

    const char* readString(std::ifstream& fileI);
    char readChar(std::ifstream& fileI);
    short readShort(std::ifstream& fileI);

    void writeString(std::ofstream& fileO, const char* string);
    void writeChar(std::ofstream& fileO, char character);
    void writeShort(std::ofstream& fileO, short number);

    bool save();
    bool load();

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