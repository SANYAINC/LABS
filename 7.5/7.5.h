#pragma once

class list {
    char *mA;
    int *mB;
    int mBeg;
    int mEnd;
    int mSize;
public:
    list(int n);
    void pushBack(char character);
    char& operator [] (int index);
    int getSize();
    void pushRepeatsFrom(list list1, list list2);
    bool find(char character);
};
