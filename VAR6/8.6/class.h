#pragma once

#include <iostream>

template <class T>
class tree {
    class branch {
    public:
        T mData;
        branch* mLeftPtr;
        branch* mRightPtr;

        branch(T data = 0, branch* leftPtr = nullptr, branch* rightPtr = nullptr);
    };

    branch* mRoot;
    int mSize;

    void NLR(branch* curBranch, void(tree::*visit)(branch*));
    void LRN(branch* curBranch, void(tree::*visit)(branch*));
    void LNR(branch* curBranch, void(tree::*visit)(branch*));

    void pushDataFrom(branch* curBranch);
    void removeNode(branch* curBranch);
    bool isLeaf(branch* curBranch);
    void printBranch(branch* curBranch);
    void printLeaf(branch* curBranch);
    void calcLeaves(branch* curBranch, int& counter);

public:

    static T invalidData;

    tree();
    tree(T data);
    tree(const tree& anotherTree);
    ~tree();

    void push(T data);
    void removeLeaf(T data);
    T find(T data);
    void show();
    void showLeaves();
    void clear();

};






template <class T>tree <T>::branch::branch(T data, branch* leftPtr, branch* rightPtr) {
    mData = data;
    mLeftPtr = leftPtr;
    mRightPtr = rightPtr;
}

template <class T> T tree<T>::invalidData = static_cast<T>(false);

template <class T>tree <T>::tree() {
    mRoot = nullptr;
    mSize = 0;
}
template <class T>tree <T>::tree(T data) {
    mRoot = new branch(data);
    mSize = 1;
}
template <class T>tree <T>::tree(const tree& anotherTree) {
    mSize = 0;
    mRoot = nullptr;
    NLR(anotherTree.mRoot, &pushDataFrom);
}
template <class T>tree <T>::~tree() {
    LRN(mRoot, &removeNode);
}

template <class T>void tree <T>::NLR(tree::branch* curBranch, void (tree::*visit)(branch*)) {
    if (curBranch) {
        (this->*visit)(curBranch);
        NLR(curBranch->mLeftPtr, visit);
        NLR(curBranch->mRightPtr, visit);
    }
}
template <class T>void tree <T>::LRN(tree::branch* curBranch, void (tree::*visit)(branch*)) {
    if (curBranch) {
        LRN(curBranch->mLeftPtr, visit);
        LRN(curBranch->mRightPtr, visit);
        (this->*visit)(curBranch);
    }
}
template <class T>void tree <T>::LNR(tree::branch* curBranch, void (tree::*visit)(branch*)) {
    if (curBranch) {
        LNR(curBranch->mLeftPtr, visit);
        (this->*visit)(curBranch);
        LNR(curBranch->mRightPtr, visit);
    }
}

template <class T>void tree <T>::pushDataFrom(tree::branch* curBranch) {
    push(curBranch->mData);
}
template <class T>void tree <T>::removeNode(tree::branch* curBranch) {
    delete curBranch;
    mSize--;
}
template <class T>bool tree <T>::isLeaf(tree::branch* curBranch) {
    return !(curBranch->mLeftPtr or curBranch->mRightPtr);
}
template <class T>void tree <T>::printBranch(tree::branch* curBranch) {
    std::cout << curBranch->mData << ", ";
}
template <class T>void tree <T>::printLeaf(tree::branch* curBranch) {
    if (isLeaf(curBranch)) {
        std::cout << curBranch->mData << ", ";
    }
}
template <class T>void tree <T>::calcLeaves(tree::branch* curBranch, int& counter) {
    if (curBranch) {
        calcLeaves(curBranch->mLeftPtr, counter);
        if (isLeaf(curBranch)) {
            counter++;
        }
        calcLeaves(curBranch->mRightPtr, counter);
    }
}

template <class T>void tree <T>::push(T data) {
    mSize++;
    if (mSize - 1 == 0) {
        mRoot = new branch(data);
        return;
    }
    branch* current = mRoot;
    while (true) {
        if (data > current->mData) {

            if (!current->mRightPtr) {
                current->mRightPtr = new branch(data);
                return;
            }

            current = current->mRightPtr;
        } else {

            if (!current->mLeftPtr) {
                current->mLeftPtr = new branch(data);
                return;
            }

            current = current->mLeftPtr;
        }
    }
}
template <class T>void tree <T>::removeLeaf(T data) {
    if (mRoot->mData == data) {
        std::cerr << "NOT A LEAF";
        exit(404);
    }
    branch* current = mRoot;
    bool leftTree = false;
    while (true) {
        if (current->mLeftPtr and current->mLeftPtr->mData == data) {
            leftTree = true;
            break;
        }
        if (current->mRightPtr and current->mRightPtr->mData == data) {
            break;
        }
        if (data < current->mData) {
            if (!current->mLeftPtr) {
                std::cerr << "NOT FOUND";
                exit(404);
            }
            current = current->mLeftPtr;
        } else {
            if (!current->mRightPtr) {
                std::cerr << "NOT FOUND";
                exit(404);
            }
            current = current->mRightPtr;
        }
    }
    if (leftTree) {
        if (!isLeaf(current->mLeftPtr)) {
            std::cerr << "NOT A LEAF";
            exit(404);
        }
        delete current->mLeftPtr;
        mSize--;
        current->mLeftPtr = nullptr;
    } else {
        if (!isLeaf(current->mRightPtr)) {
            std::cerr << "NOT A LEAF";
            exit(404);
        }
        delete current->mRightPtr;
        mSize--;
        current->mRightPtr = nullptr;
    }
}
template <class T>T tree <T>::find(T data) {
    branch* current = mRoot;
    while (true) {
        if (current->mData == data) {
            return current->mData;
        }
        if (data < current->mData) {
            if (!current->mLeftPtr) {
                return invalidData;
            }
            current = current->mLeftPtr;
        } else {
            if (!current->mRightPtr) {
                return invalidData;
            }
            current = current->mRightPtr;
        }
    }
}
template <class T>void tree <T>::show() {
    if (mSize == 0) {
        std::cout << "[ ]";
        return;
    }
    std::cout << "[";
    LNR(mRoot, &printBranch);
    std::cout << "\b\b]";
}
template <class T>void tree <T>::showLeaves() {
    int leaves = 0;
    calcLeaves(mRoot, leaves);
    if (leaves == 0) {
        std::cout << "[ ]";
        return;
    }
    std::cout << "[";
    LNR(mRoot, &printLeaf);
    std::cout << "\b\b]";
}
template <class T>void tree <T>::clear() {
    void(tree::*destroyer)(branch*) = &removeNode;
    LRN(mRoot, destroyer);
    mRoot = nullptr;
}



