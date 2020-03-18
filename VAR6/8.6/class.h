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
    void printAsTree(branch* curBranch, int level);
public:

    static T invalidData;

    tree();
    tree(T data);
    tree(const tree& anotherTree);
    ~tree();

    void push(T data);
    void removeLeaf(T data);
    T find(T data);
    void show(char type = 'L');
    void showLeaves();
    void clear();

};

template <class T>
T tree<T>::invalidData = static_cast<T>(false);

template <class T>
tree <T>::branch::branch(T data, branch* leftPtr, branch* rightPtr) {
    mData = static_cast<T>(data);
    mLeftPtr = leftPtr;
    mRightPtr = rightPtr;
}

template <class T>
tree <T>::tree() {
    mRoot = nullptr;
    mSize = 0;
}

template <class T>
tree <T>::tree(T data) {
    mRoot = new branch(data);
    mSize = 1;
}

template <class T>
tree <T>::tree(const tree& anotherTree) {
    mSize = 0;
    mRoot = nullptr;
    void(tree::*appendVisited)(branch*) = &pushDataFrom;
    NLR(anotherTree.mRoot, appendVisited);
}

template <class T>
void tree <T>::NLR(tree::branch* curBranch, void (tree::*visit)(branch*)) {
    if (curBranch) {
        (this->*visit)(curBranch);
        NLR(curBranch->mLeftPtr, visit);
        NLR(curBranch->mRightPtr, visit);
    }
}

template <class T>
void tree <T>::pushDataFrom(tree::branch* curBranch) {
    push(curBranch->mData);
}

template <class T>
void tree <T>::push(T data) {
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

template <class T>
tree <T>::~tree() {
    void(tree::*destroyer)(branch*) = &removeNode;
    LRN(mRoot, destroyer);
}

template <class T>
void tree <T>::removeNode(tree::branch* curBranch) {
    delete curBranch;
    mSize--;
}

template <class T>
void tree <T>::LRN(tree::branch* curBranch, void (tree::*visit)(branch*)) {
    if (curBranch) {
        LRN(curBranch->mLeftPtr, visit);
        LRN(curBranch->mRightPtr, visit);
        (this->*visit)(curBranch);
    }
}

template <class T>
T tree <T>::find(T data) {
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

template <class T>
void tree <T>::removeLeaf(T data) {
    if (mRoot->mData == data) {
        std::cerr << "NOT A LEAF";
        exit(404);
    }
    branch* current = mRoot;
    while (true) {
        if (current->mLeftPtr and current->mLeftPtr->mData == data) {
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
    if (current->mLeftPtr->mData == data) {
        if (!isLeaf(current->mLeftPtr)) {
            std::cerr << "NOT A LEAF";
            exit(404);
        }
        delete current->mLeftPtr;
        current->mLeftPtr = nullptr;
    } else {
        if (!isLeaf(current->mRightPtr)) {
            std::cerr << "NOT A LEAF";
            exit(404);
        }
        delete current->mRightPtr;
        current->mRightPtr = nullptr;
    }
}

template <class T>
bool tree <T>::isLeaf(tree::branch* curBranch) {
    return !(curBranch->mLeftPtr or curBranch->mRightPtr);
}

template <class T>
void tree <T>::show(char type) {
    if (type == 'T') {
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        printAsTree(mRoot, 0);
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    }
    if (type == 'L') {
        void(tree::*showBranch)(branch*) = &printBranch;
        std::cout << "[";
        LNR(mRoot, showBranch);
        std::cout << "\b\b]";
    }
}

template <class T>
void tree <T>::printBranch(tree::branch* curBranch) {
    std::cout << curBranch->mData << ", ";
}

template <class T>
void tree <T>::LNR(tree::branch* curBranch, void (tree::*visit)(branch*)) {
    if (curBranch) {
        LNR(curBranch->mLeftPtr, visit);
        (this->*visit)(curBranch);
        LNR(curBranch->mRightPtr, visit);
    }
}

template <class T>
void tree <T>::printAsTree(tree::branch* curBranch, int level) {
    if (curBranch) {
        printAsTree(curBranch->mLeftPtr, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "     ";
        }
        std::cout << curBranch->mData << std::endl;
        printAsTree(curBranch->mRightPtr, level + 1);
    }
}

template <class T>
void tree <T>::showLeaves() {
    std::cout << "[";
    void(tree::*showLeaf)(branch*) = &printLeaf;
    LNR(mRoot, showLeaf);
    std::cout << "\b\b]";
}

template <class T>
void tree <T>::printLeaf(tree::branch* curBranch) {
    if (isLeaf(curBranch)) {
        std::cout << curBranch->mData << ", ";
    }
}

