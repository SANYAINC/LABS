#pragma once

template <class T>
class tree {
    class branch {
    public:
        T data;
        branch* mLeftPtr;
        branch* mRightPtr;

        branch();
    };

    branch* root;
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