#include <iostream>

using namespace std;

class list {
    class unit {
    public:
        int mData;
        unit *mPrevPtr;
        unit *mNextPtr;
        unit(int mData, unit *prevPtr = nullptr, unit *nextPtr = nullptr);
        void print();
    };
    unit *mHead;
    unit *mTail;
    int mSize;
public:
    list();
    void pushBack(int number);
    void pushBack(int *array, int length);
    int& operator [] (int index);
    int getSize();
    int calculateProd();
};