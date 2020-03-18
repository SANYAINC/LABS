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
