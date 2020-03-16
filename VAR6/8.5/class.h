#pragma once

int number = 1;

template <class T>
class list {
    class node {
    public:
        T mData;
        node* mNextPtr;
        node* mPrevPtr;

        node(T data = 0, node* mNextPtr = nullptr, node* mPrevPtr = nullptr);
    };

    node* mHead;
    node* mTail;
    int mSize;
public:
    list();
    list(int size);
    list(const list& anotherList);

    T& operator[](int index) const;

    int getSize() const;
};





template <class T>
list <T>::node::node(T data, node* nextPtr, node* prevPtr) {
    mData = static_cast<T>(data);
    mNextPtr = nextPtr;
    mPrevPtr = prevPtr;
}

template <class T>
list <T>::list() {
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
}

template <class T>
list <T>::list(int size) {
    mSize = size;

    mHead = new node;
    mTail = mHead;
    size--;

    node* current = mHead;
    while (current->mNextPtr) {
        current = current->mNextPtr;
    }
    for (int i = 0; i < size; ++i) {
        current->mNextPtr = new node(0, nullptr, current);
        current = current->mNextPtr;
        mTail = current;
    }

}

template <class T>
list <T>::list(const list& anotherList) {
    int newSize = anotherList.getSize();
    mSize = newSize;
    if (mSize == 0) {
        mHead = nullptr;
        mTail = nullptr;
    }
    int counter = 0;
    mHead = new node(anotherList[counter++]);
    mTail = mHead;
    newSize--;

    node* current = mHead;
    while (current->mNextPtr) {
        current = current->mNextPtr;
    }
    for (int i = 0; i < newSize; ++i) {
        current->mNextPtr = new node(anotherList[counter++], nullptr, current);
        current = current->mNextPtr;
        mTail = current;
    }

}

template <class T>
T& list <T>::operator[](int index) const {
    if (index < 0 or index >= getSize()) {
        std::cerr << "INDEX OUT OF RANGE" << std::endl;
    }
    node* current;
    int counter = 0;
    if (index < getSize() / 2) {
        current = mHead;
        while (counter != index) {
            current = current->mNextPtr;
            counter++;
        }
        return current->mData;
    } else {
        current = mTail;
        while (counter != index) {
            current = current->mPrevPtr;
            counter++;
        }
        return current->mData;
    }

}

template <class T>
int list <T>::getSize() const {
    return mSize;
}



