#pragma once

#include "Entities.h"

#define VECTOR_SIZE_INIT 2
#define VECTOR_PATH_TO_STORAGE "../VAR6/10/vector.bin"

class container {
public:
    virtual entity* operator[](int position) const = 0;

    virtual void print() const = 0;

    virtual void pushBack(entity& object) = 0;

    virtual void pushAt(int position, entity& object) = 0;

    virtual void removeAt(int position) = 0;

    virtual int getSize() const = 0;

    virtual ~container() { };
};



class vector : public container {
    entity** mVector;
    int mCapacity;
    int mSize;

    void resize(int newCapacity);

    void identifyAndPush(entity** vector, entity* object, int index);

public:
    vector();
    vector(int capacity);
    vector(const vector& anotherVector);
    vector(vector&& anotherVector);
    ~vector() override;

    vector& operator=(const vector& anotherVector);
    vector& operator=(vector&& anotherVector);
    entity* operator[](int position) const override;

    void print() const override;

    void pushBack(entity& object) override;

    void pushAt(int position, entity& object) override;

    void removeAt(int position) override;

    int getSize() const override;

    int getCapacity() const;

    void clear();
};

class list : public container {
    class node {
    public:
        entity* mData;
        node* mNextPtr;

        node(entity* data);
        ~node();
    };

    node* mHead;
    int mSize;
public:
    list();
    list(const list& anotherList);
    list(list&& anotherList);
    ~list() override;

    list& operator=(const list& anotherList);
    list& operator=(list&& anotherList);

    entity* operator[](int position) const override;

    void print() const override;

    void pushBack(entity& data) override;

    void pushAt(int position, entity& data) override;

    void removeAt(int position) override;

    int getSize() const override;

    void clear();
};