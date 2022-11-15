#ifndef ADT_BST_TREE_BST_H
#define ADT_BST_TREE_BST_H

#include <iostream>
#include "ForwardIterator.h"
#include "ReverseIterator.h"

using namespace std;

struct Trunk {
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

template<typename V, typename T>
class BST {
public:
    friend class ForwardIterator<V, T>;

    friend class ReverseIterator<V, T>;

    explicit BST();

    BST(BST &obj);

    ~BST();

    T getElement(V k);

    bool changeElement(V k, T val);

    void insert(V k, T val);

    bool remove(V k);

    void printTree();

    int getSize();

    bool clear();

    bool isEmpty();

    void printKeys();

    int getIndex(V k);

    int getStat();

    ForwardIterator<V, T> begin() {
        return ForwardIterator(root, 1);
    }

    ForwardIterator<V, T> end() {
        return ForwardIterator(root, -1);
    }

    ReverseIterator<V, T> rbegin() {
        return ReverseIterator(root, 1);
    }

    ReverseIterator<V, T> rend() {
        return ReverseIterator(root, -1);
    }

private:
    TreeNode<V, T> *root;
    int count;
    int num;
    int stat;

    void destructor(TreeNode<V, T> *);

    TreeNode<V, T> *doInsert(TreeNode<V, T> *, V k, T val);

    TreeNode<V, T> *doRemove(TreeNode<V, T> *, V k, bool *flag);

    TreeNode<V, T> *findMin(TreeNode<V, T> *, TreeNode<V, T> *);

    void print(TreeNode<V, T> *node, Trunk *prev, bool isLeft);

    void print(TreeNode<V, T> *node);

    T search(TreeNode<V, T> *node, V k);

    bool write(TreeNode<V, T> *node, V k, T val);

    void showTrunks(Trunk *p);

    void roundTree(TreeNode<V, T> *node, V k, int *ind);

};


#endif //ADT_BST_TREE_BST_H
