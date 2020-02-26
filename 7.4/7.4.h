#pragma once

class list {
    class unit {
    public:
        char mCharacter;
        unit *mNextPtr;
        unit(char character, unit *nextPtr = nullptr);
        char getData();
    };

    unit *mHead;
    int mSize;
public:
    list();
    int getSize();
    void pushBack(char character);
    char& operator [](int index);

    bool find(char character);

    static void selectRepeatsFrom(list &list1, list &list2, list &list3);
};