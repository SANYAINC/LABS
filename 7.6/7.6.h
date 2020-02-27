class list {
    class unit {
    public:
        int mData;
        unit *mPrevPtr;
        unit *mNextPtr;
        unit(int mData, unit *prevPtr = nullptr, unit *nextPtr = nullptr);
    };
    unit *mHead;
    unit *mTail;
    int mSize;
public:
    list();
    void pushBack(int number);
};