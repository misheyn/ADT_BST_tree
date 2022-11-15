#ifndef ADT_BST_TREE_REVERSEITERATOR_H
#define ADT_BST_TREE_REVERSEITERATOR_H

#include "TreeNode.h"

template<typename V, typename T>
class ReverseIterator {
public:
    ReverseIterator(TreeNode<V, T> *tmp, int f) {
        statusFlag = f;
        node = tmp;
        if (node) fillList(node);
        if (f == 1) it = listTree.begin();
        else if (f == -1) it = listTree.end();
    }

    T &operator*() {
        return (*it)->data;
    }

    ReverseIterator operator++(int) {
        it--;
        return *this;
    }

    ReverseIterator operator--(int) {
        it++;
        return *this;
    }

    friend bool operator==(const ReverseIterator &f, const ReverseIterator &s) {
        return *(f.it) = *(s.it);
    }

    friend bool operator!=(const ReverseIterator &f, const ReverseIterator &s) {
        return *(f.it) != *(s.it);
    }

    int getStatus() {
        return statusFlag;
    }


private:
    TreeNode<V, T> *node;
    list<TreeNode<V, T> *> listTree;
    typename list<TreeNode<V, T> *>::iterator it;
    int statusFlag;

    void fillList(TreeNode<V, T> *r) {
        if (r == nullptr) return;
        fillList(r->left);
        listTree.push_front(r);
        fillList(r->right);
    }
};

#endif //ADT_BST_TREE_REVERSEITERATOR_H
