#include <iostream>
#include "../../Containers.h"

list::node::node(entity* data) {
    char type = data->type();

    switch (type) {
        case HUMAN_ID: {
            mData = new human(*dynamic_cast<human*>(data));
            break;
        }
        case ITEM_ID: {
            mData = new item(*dynamic_cast<item*>(data));
            break;
        }
        case BIKE_ID: {
            mData = new bike(*dynamic_cast<bike*>(data));
            break;
        }
        case CYCLIST_ID: {
            mData = new cyclist(*dynamic_cast<cyclist*>(data));
            break;
        }
        case CAR_ID: {
            mData = new car(*dynamic_cast<car*>(data));
            break;
        }
    }

    mNextPtr = nullptr;
}

list::node::~node() {
    delete mData;
}

list::list() {
    mHead = nullptr;
    mSize = 0;
}

list::list(const list& anotherList) {
    mSize = anotherList.mSize;

    if (mSize == 0) {
        mHead = nullptr;
        return;
    }

    int counter = 0;
    mHead = new node(anotherList[counter++]);

    node* current = mHead;

    for (int i = 0; i < mSize - 1; ++i) {
        current->mNextPtr = new node(anotherList[counter++]);
        current = current->mNextPtr;
    }
}

list::list(list&& anotherList) {
    mHead = anotherList.mHead;
    mSize = anotherList.mSize;

    anotherList.mHead = nullptr;
}

list::~list() {
    clear();
}

entity* list::operator[](int position) const {
    if (position < 0 or position >= mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    int counter = 0;
    node* current = mHead;

    while (counter++ != position) {
        current = current->mNextPtr;
    }

    return current->mData;
}

list& list::operator=(const list& anotherList) {
    if (&anotherList == this) {
        return *this;
    }

    clear();

    for (int i = 0; i < anotherList.getSize(); ++i) {
        this->pushBack(*anotherList[i]);
    }
    return *this;
}

list& list::operator=(list&& anotherList) {
    if (&anotherList == this) {
        return *this;
    }

    clear();

    mHead = anotherList.mHead;
    mSize = anotherList.mSize;

    anotherList.mHead = nullptr;

    return *this;
}

void list::print() const {
    node* current = mHead;
    while (current) {
        current->mData->print();
        current = current->mNextPtr;
    }
}

void list::pushBack(entity& data) {

    if (mSize == 0) {
        mHead = new node(&data);
    } else {
        node* current = mHead;
        while (current->mNextPtr != nullptr) {
            current = current->mNextPtr;
        }
        current->mNextPtr = new node(&data);
    }

    mSize++;
}

void list::pushAt(int position, entity& data) {
    if (position < 0 or position > mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    if (position == mSize) {
        pushBack(data);
        return;
    }

    node* current = mHead;

    if (position == 0) {
        mHead = new node(&data);
        mHead->mNextPtr = current;
    } else {
        int counter = 0;

        while (counter++ != position - 1) {
            current = current->mNextPtr;
        }
        node *next = current->mNextPtr;
        current->mNextPtr = new node(&data);
        current->mNextPtr->mNextPtr = next;
    }

    mSize++;
}

void list::removeAt(int position) {
    if (position < 0 or position >= mSize) {
        std::cerr << "INVALID INDEX: " << position << std::endl;
        exit(1008);
    }

    int counter = 0;
    node* current = mHead;

    if (position == 0) {
        current = current->mNextPtr;
        delete mHead;
        mHead = current;
    } else {
        while (counter++ != position - 1) {
            current = current->mNextPtr;
        }
        node* next = current->mNextPtr->mNextPtr;
        delete current->mNextPtr;
        current->mNextPtr = next;
    }
    mSize--;
}

int list::getSize() const {
    return mSize;
}

void list::clear() {
    node* next;
    while (mHead) {
        next = mHead;
        mHead = next->mNextPtr;
        delete next;
    }
    mSize = 0;
}
