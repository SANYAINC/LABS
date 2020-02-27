#pragma once
#include <iostream>
using namespace std;

//TODO Перегркзить квадратные скобки

template <class T>
class tree{
    class branch {
    public:
        T mData;
        branch *mLeftPtr;
        branch *mRightPtr;
        branch(T data, branch *leftPtr = nullptr, branch *rightPtr = nullptr);

    };
    branch *mRoot;
    int mSize;
    void showInit(branch *current);
    int findInit(branch *current, T data);
public:
    tree();
    void push(T data);
    void show();
    int find(T data);
};









template<class T>
tree<T>::branch::branch(T data, tree::branch *leftPtr, tree::branch *rightPtr) {
    mData = data;
    mLeftPtr = leftPtr;
    mRightPtr = rightPtr;
}

template<class T>
tree<T>::tree() {
    mRoot = nullptr;
    mSize = 0;
}

template<class T>
void tree<T>::push(T data) {
    if (mSize == 0) {
        mRoot = new branch(data);
        mSize++;
    } else {
        branch *current = mRoot;
        while (true) {
            if (current->mData > data) {
                if (current->mLeftPtr == nullptr) {
                    current->mLeftPtr = new branch(data);
                    return;
                }
                current = current->mLeftPtr;
            } else {
                if (current->mRightPtr == nullptr) {
                    current->mRightPtr = new branch(data);
                    return;
                }
                current = current->mRightPtr;
            }
        }
    }
}

template<class T>
void tree<T>::show() {
    branch *current = mRoot;
    showInit(current);
    cout << endl;
}

template<class T>
void tree<T>::showInit(tree::branch *current) {
    if (current) {
        showInit(current->mLeftPtr);
        cout << current->mData << ' ';
        showInit(current->mRightPtr);
    }
}


template<class T>
int tree<T>::find(T data) {
    branch *current = mRoot;
    int counter = 0;
    return findInit(current, data);
}

template<class T>
int tree<T>::findInit(tree::branch *current, T data) {
    static int cou = 0;
    static int counter = -1;
    if (current) {
        findInit(current->mLeftPtr, data);
        if (current->mData == data) {
            counter = cou;
        } else {
            cou++;
        }
        findInit(current->mRightPtr, data);
    }
    return counter >= 0 ? counter : -1;
}


