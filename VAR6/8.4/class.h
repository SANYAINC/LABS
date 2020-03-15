#pragma once
#include <iostream>
#include <ctime>

template <class T>
class list {
    class node {
    public:
        T mData;
        node* mNextPtr;

        node(T defaultData);
    };

    node* mHead;
    int mSize;
public:
    list();
    list(int size, T defaultData);
    list(const list& anotherList);
    ~list();

    T& operator[](int index) const;
    list<T>& operator=(const list<T>& anotherList);

    void pushBack(T data);
    void pushAt(int index, T data);
    void deleteAt(int index);
    int find(T data) const;
    void show() const;
    int getSize() const;
    void fillRandom(int range = 30, int shift = 45);
    void pushRepeatsFrom(const list<T>& list1, const list<T>& list2);

    void clear();
};

template <class T>
list <T>::node::node(T defaultData) {
    mData = defaultData;
    mNextPtr = nullptr;
}

template <class T>
list <T>::~list() {
    clear();
}

template <class T>
list <T>::list() {
    mHead = nullptr;
    mSize = 0;
}

template <class T>
list <T>::list(int size, T defaultData) {
    if (size <= 0) {
        std::cerr << "BAD SIZE" << std::endl;
        exit(404);
    }

    mHead = new node(defaultData);
    mSize = size--;

    node* current = mHead;

    for (; size > 0; --size) {
        current->mNextPtr = new node(defaultData);
        current = current->mNextPtr;
    }
}

template <class T>
list <T>::list(const list& anotherList) {
    int newSize = anotherList.getSize();
    mSize = newSize;
    if (newSize == 0) {
        mHead = nullptr;
        return;
    }


    int counter = 0;
    mHead = new node(anotherList[counter++]);
    newSize--;
    node* current = mHead;

    for (; newSize > 0 ; --newSize) {
        current->mNextPtr = new node(anotherList[counter++]);
        current = current->mNextPtr;
    }
}

template <class T>
T& list <T>::operator[](const int index) const{
    int size = getSize();
    if (index < 0 or index >= size) {
        std::cerr << "INDEX " << index << " IS OUT OF RANGE (0 - " << size << ")";
        exit(404);
    }

    int counter = 0;
    node* current = mHead;

    for (; counter != index; ++counter) {
        current = current->mNextPtr;
    }
    return current->mData;
}

template <class T>
int list <T>::getSize() const {
    return mSize;
}

template <class T>
void list <T>::show() const {
    int size = getSize();
    std::cout << "[";
    if (size == 0) {
        std::cout << " ]";
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << (*this)[i];
        if (i != size - 1) {
            std::cout << ", ";
        } else {
            std::cout << "]";
        }
    }
}

template <class T>
void list <T>::pushBack(const T data) {
    if (!mSize) {
        mHead = new node(data);
        mSize++;
        return;
    }

    node* current = mHead;
    while (current->mNextPtr) {
        current = current->mNextPtr;
    }

    current->mNextPtr = new node(data);
    mSize++;
}

template <class T>
void list <T>::pushAt(int index, T data) {
    int size = getSize();
    if (index < 0 or index > size) {
        std::cerr << "INDEX " << index << " IS OUT OF RANGE (0 - " << size << ")";
        exit(404);
    }
    if (index == size) {
        pushBack(data);
        return;
    }
    node* current = mHead;
    if (!index) {
        mHead = new node(data);
        mHead->mNextPtr = current;
        mSize++;
        return;
    }
    int counter = 0;

    while (counter != index - 1) {
        current = current->mNextPtr;
        counter++;
    }
    node *next = current->mNextPtr;
    current->mNextPtr = new node(data);
    current->mNextPtr->mNextPtr = next;
    mSize++;
}

template <class T>
int list <T>::find(T data) const {
    if (!mSize) {
        return -1;
    }
    int counter = 0;
    node *current = mHead;
    while (current and current->mData != data) {
        current = current->mNextPtr;
        counter++;
    }
    if (current != nullptr) {
        return counter;
    } else {
        return -1;
    }
}

template <class T>
void list <T>::deleteAt(int index) {
    int size = getSize();
    if (index < 0 or index >= size) {
        std::cerr << "INDEX " << index << " IS OUT OF RANGE (0 - " << size << ")";
        exit(404);
    }

    int counter = 0;
    node* current = mHead;
    if (!index) {
        current = current->mNextPtr;
        delete mHead;
        mHead = current;
        mSize--;
        return;
    }
    while (counter != index - 1) {
        current = current->mNextPtr;
        counter++;
    }
    node* next = current->mNextPtr->mNextPtr;
    delete current->mNextPtr;
    current->mNextPtr = next;
    mSize--;
}

template <class T>
void list <T>::clear() {
    node* next;
    while (mHead) {
        next = mHead;
        mHead = next->mNextPtr;
        delete next;
    }
    mSize = 0;
}

template <class T>
list <T> & list <T>::operator=(const list<T>& anotherList) {
    int newSize = anotherList.getSize();
    int oldSize = getSize();
    if (!newSize) {
        this->clear();
    }

    if (oldSize < newSize) {
        T filler = anotherList[0];
        int dSize = newSize - oldSize;
        for (int i = 0; i < dSize; ++i) {
            this->pushBack(filler);
        }
        for (int j = 0; j < newSize; ++j) {
            (*this)[j] = anotherList[j];
        }
        return *this;
    }

    if (oldSize > newSize) {
        int dSize = oldSize - newSize;
        for (int i = 0; i < dSize; ++i) {
            (*this).deleteAt(getSize()-1);
        }
        for (int j = 0; j < newSize; ++j) {
            (*this)[j] = anotherList[j];
        }
        return *this;
    }

    for (int k = 0; k < newSize; ++k) {
        (*this)[k] = anotherList[k];
    }
    return *this;

}

template <class T>
void list <T>::fillRandom(int range, int shift) {
    int size = getSize();
    for (int i = 0; i < size; ++i) {
        (*this)[i] = static_cast<T>(rand()%range + shift);
    }
}

template <class T>
void list <T>::pushRepeatsFrom(const list<T>& list1, const list<T>& list2) {
    int size1 = list1.getSize();
    char buffer;
    for (int i = 0; i < size1; ++i) {
        buffer = list1[i];
        if (list2.find(buffer) != -1 and find(buffer) == -1) {
            pushBack(buffer);
        }
    }
}

