#pragma once

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
    ~list();

    T& operator[](int index) const;

    int getProd()const;
    void pushBack(T data);
    void pushAt(int index, T data);
    void deleteAt(int index);
    int find(T data);
    void clear();
    void print() const;
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

    //Инициализация первого элемента списка
    mHead = new node;
    mTail = mHead;
    size--;

    node* current = mHead;
    for (int i = 0; i < size; ++i) {
        current->mNextPtr = new node(0, nullptr, current);
        current = current->mNextPtr;
        mTail = current;
    }

}

template <class T>
list <T>::list(const list& anotherList) {
    int size = anotherList.getSize();
    mSize = size;

    //Инициализация первого элемента списка
    node* currentSecond = anotherList.mHead;
    mHead = new node(currentSecond->mData);
    mTail = mHead;
    size--;
    currentSecond = currentSecond->mNextPtr;

    node* current = mHead;
    for (int i = 0; i < size; ++i) {
        current->mNextPtr = new node(currentSecond->mData, nullptr, current);
        current = current->mNextPtr;
        currentSecond = currentSecond->mNextPtr;
        mTail = current;
    }

}

template <class T>
T& list <T>::operator[](int index) const {
    if (index < 0 or index >= getSize()) {
        std::cerr << "INDEX OUT OF RANGE" << std::endl;
    }
    node* current;
    int counter;
    if (index < mSize / 2) {
        counter = 0;
        current = mHead;
        while (counter != index) {
            current = current->mNextPtr;
            counter++;
        }
    } else {
        counter = getSize() - 1;
        current = mTail;
        while (counter != index) {
            current = current->mPrevPtr;
            counter--;
        }
    }
    return current->mData;
}

template <class T>
int list <T>::getSize() const {
    return mSize;
}

template <class T>
void list <T>::pushBack(T data) {
    if (mSize == 0) {
        mHead = new node(data);
        mTail = mHead;
        mSize++;
        return;
    }
    //Добавление в конец
    node* current = mTail;
    current->mNextPtr = new node(data, nullptr, current);
    mTail = current->mNextPtr;
    mSize++;
}

template <class T>
void list <T>::pushAt(int index, T data) {
    if (index < 0 or index > mSize) {
        std::cerr << "INDEX " << index << " IS OUT OF RANGE (0 - " << mSize << ")";
        exit(404);
    }

    if (index == mSize) {
        pushBack(data);
        return;
    }

    node* current;
    if (index == 0) {
        mSize++;
        current = mHead;
        mHead = new node(data, current);
        current->mPrevPtr = mHead;
        return;
    }

    //Поиск места вставки
    int counter;
    node* buffer;
    if (index < mSize / 2) {
        counter = 0;
        current = mHead;
        while (counter != index - 1) {
            current = current->mNextPtr;
            counter++;
        }
    } else {
        counter = mSize - 1;
        current = mTail;
        while (counter != index - 1) {
            current = current->mPrevPtr;
            counter--;
        }
    }

    //Вставка
    buffer = current->mNextPtr;
    current->mNextPtr = new node(data, buffer, current);
    buffer->mPrevPtr = current->mNextPtr;
    mSize++;
}

template <class T>
void list <T>::deleteAt(int index) {
    if (index < 0 or index >= mSize) {
        std::cerr << "INDEX " << index << " IS OUT OF RANGE (0 - " << mSize << ")";
        exit(404);
    }


    //Удаление первого элемента
    node* current;
    if (index == 0) {
        if (mSize == 1) {
            delete mHead;
            mHead = nullptr;
            mTail = nullptr;
        } else {
            current = mHead->mNextPtr;
            delete mHead;
            mHead = current;
            mHead->mPrevPtr = nullptr;
        }
        mSize--;
        return;
    }

    //Удаление последнего элемента
    if (index == mSize - 1) {
        current = mTail->mPrevPtr;
        delete mTail;
        mTail = current;
        current->mNextPtr = nullptr;
        mSize--;
        return;
    }

    //Удаление из середины списка
    int counter;
    if (index < mSize / 2) {
        counter = 0;
        current = mHead;
        while (counter != index) {
            current = current->mNextPtr;
            counter++;
        }
    } else {
        counter = mSize - 1;
        current = mTail;
        while (counter != index) {
            current = current->mPrevPtr;
            counter--;
        }
    }
    current->mPrevPtr->mNextPtr = current->mNextPtr;
    current->mNextPtr->mPrevPtr = current->mPrevPtr;
    mSize--;
    delete current;
}

template <class T>
void list <T>::clear() {
    node* current;
    while (mHead) {
        current = mHead;
        mHead = current->mNextPtr;
        delete current;
    }
    mSize = 0;
}

template <class T>
list <T>::~list() {
    clear();
}

template <class T>
void list <T>::print() const {
    std::cout << "[";
    if (mSize == 0) {
        std::cout << " ]";
        return;
    }
    for (int i = 0; i < mSize; ++i) {
        std::cout << (*this)[i];
        if (i == mSize - 1) {
            std::cout << "]";
        } else {
            std::cout << ", ";
        }
    }
}

template <class T>
int list <T>::find(T data) {
    if (!mSize) {
        return -1;
    }
    int counterHead = 0;
    int counterTail = mSize - 1;
    while (counterHead <= counterTail) {
        if ((*this)[counterHead] == data) {
            return counterHead;
        }
        if ((*this)[counterTail] == data) {
            return counterTail;
        }
        counterHead++;
        counterTail--;
    }
    return -1;
}

template <class T>
int list <T>::getProd() const{
    int max = mSize;
    int sum = 1;
    int cou1 = 0; //счетчик от нуля до половины
    int cou2 = max - 1; //Счетчик от конца до половины
    for (int i = 0; i < max / 2; ++i) {
        sum *= (*this)[cou1++] - (*this)[cou2--]; //Перемножение
    }
    return sum;
}



