#ifndef ADT_BST_TREE_FORWARDITERATOR_H
#define ADT_BST_TREE_FORWARDITERATOR_H

#include "TreeNode.h"
#include <list>

using namespace std;

template<typename V, typename T>
class ForwardIterator {
public:
    ForwardIterator(TreeNode<V, T> *tmp, int f) {
        statusFlag = f;
        node = tmp;
        if (node) fillList(node);
        if (f == 1) it = listTree.begin();
        else if (f == -1) it = listTree.end();
    }

    T &operator*() {
        return (*it)->data;
    }

    ForwardIterator operator++(int) {
        it++;
        return *this;
    }

    ForwardIterator operator--(int) {
        it--;
        return *this;
    }

    friend bool operator==(const ForwardIterator &f, const ForwardIterator &s) {
        return *(f.it) = *(s.it);
    }

    friend bool operator!=(const ForwardIterator &f, const ForwardIterator &s) {
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
        listTree.push_back(r);
        fillList(r->right);
    }
};

#endif //ADT_BST_TREE_FORWARDITERATOR_H
