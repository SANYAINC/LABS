#pragma once

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
    void pushDataFrom(branch* curBranch);

public:

    tree();
    tree(T data);
    tree(const tree& anotherTree);
    ~tree();

    void push(T data);
    void removeLeaf(T data);
    void find(T data);
    void show();
    void showLeaves();
    void clear();

};

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