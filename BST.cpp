#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

template<typename V, typename T>
BST<V, T>::BST() {
    root = nullptr;
    count = 0;
    num = -1;
    stat = 0;
}

template<typename V, typename T>
BST<V, T>::BST(BST &obj) {
    root = obj.root;
    count = obj.count;
}

template<typename V, typename T>
BST<V, T>::~BST() {
    destructor(root);
}

template<typename V, typename T>
void BST<V, T>::destructor(TreeNode<V, T> *node) {
    if (node != nullptr) {
        destructor(node->left);
        destructor(node->right);

        delete node;
    }
}

template<typename V, typename T>
T BST<V, T>::getElement(V k) {
    stat = 0;
    return search(root, k);
}

template<typename V, typename T>
bool BST<V, T>::changeElement(V k, T val) {
    return write(root, k, val);
}

template<typename V, typename T>
T BST<V, T>::search(TreeNode<V, T> *node, V k) {
    stat++;
    if (node == nullptr) return -1;
    if (k == node->key) return node->data;

    if (k < node->key) return search(node->left, k);
    else return search(node->right, k);
}

template<typename V, typename T>
bool BST<V, T>::write(TreeNode<V, T> *node, V k, T val) {
    stat++;
    if (node == nullptr) return false;

    if (k == node->key) {
        node->data = val;
        return true;
    }
    if (k < node->key) write(node->left, k, val);
    else write(node->right, k, val);
}

template<typename V, typename T>
void BST<V, T>::insert(V k, T val) {
    count++;
    stat = 0;
    root = doInsert(root, k, val);
}

template<typename V, typename T>
typename ::TreeNode<V, T> *BST<V, T>::doInsert(TreeNode<V, T> *node, V k, T val) {
    stat++;
    if (node == nullptr) {
        return new TreeNode(k, val);
    }
    if (k == node->key) {
        return node;
    }
    if (k < node->key) node->left = doInsert(node->left, k, val);
    else node->right = doInsert(node->right, k, val);
    return node;
}

template<typename V, typename T>
bool BST<V, T>::remove(V k) {
    bool flag = false;
    stat = 0;
    root = doRemove(root, k, &flag);
    count--;
    return flag;
}

template<typename V, typename T>
typename ::TreeNode<V, T> *BST<V, T>::doRemove(TreeNode<V, T> *node, V k, bool *flag) {
    stat++;
    if (node == nullptr) {
        *flag = false;
        return node;
    }
    if (k < node->key) {
        node->left = doRemove(node->left, k, flag);
        return node;
    }
    if (k > node->key) {
        node->right = doRemove(node->right, k, flag);
        return node;
    }
    *flag = true;
    if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
    }
    if (node->left == nullptr) {
        TreeNode<V, T> *tmp = node->right;
        delete node;
        return tmp;
    }
    if (node->right == nullptr) {
        TreeNode<V, T> *tmp = node->left;
        delete node;
        return tmp;
    }
    node->right = findMin(node->right, node);
    return node;
}

template<typename V, typename T>
typename ::TreeNode<V, T> *BST<V, T>::findMin(TreeNode<V, T> *node, TreeNode<V, T> *node0) {
    if (node->left != nullptr) {
        node->left = findMin(node->left, node0);
        return node;
    }
    node0->key = node->key;
    node0->data = node->data;
    TreeNode<V, T> *tmp = node->right;
    delete node;
    return tmp;
}

template<typename V, typename T>
void BST<V, T>::showTrunks(Trunk *p) {
    if (p == nullptr) {
        return;
    }
    showTrunks(p->prev);
    cout << p->str;
}

template<typename V, typename T>
void BST<V, T>::print(TreeNode<V, T> *node, Trunk *prev, bool isLeft) {
    if (node == nullptr) return;

    string prev_str = "    ";
    auto *trunk = new Trunk(prev, prev_str);

    print(node->right, trunk, true);

    if (!prev) {
        trunk->str = "---";
    } else if (isLeft) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << " " << node->key << ":" << node->data << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    print(node->left, trunk, false);

}

template<typename V, typename T>
void BST<V, T>::print(TreeNode<V, T> *node) {
    if (node == nullptr) return;

    cout << " " << node->key << endl;

    print(node->left);
    print(node->right);
}

template<typename V, typename T>
void BST<V, T>::printKeys() {
    if (count == 0) cout << "Tree is empty" << endl;
    else print(root);
}

template<typename V, typename T>
void BST<V, T>::printTree() {
    if (count == 0) cout << "Tree is empty" << endl;
    else print(root, nullptr, false);
}

template<typename V, typename T>
int BST<V, T>::getSize() {
    return count;
}

template<typename V, typename T>
bool BST<V, T>::clear() {
    bool flag = false;
    while (root != nullptr) root = doRemove(root, root->key, &flag);
    return flag;
}

template<typename V, typename T>
bool BST<V, T>::isEmpty() {
    if (root == nullptr) return true;
    else return false;
}

template<typename V, typename T>
int BST<V, T>::getIndex(V k) {
    int ind = -1;
    roundTree(root, k, &ind);
    num = 0;
    return ind;
}

template<typename V, typename T>
void BST<V, T>::roundTree(TreeNode<V, T> *node, V k, int *ind) {
    if (node == nullptr) return;
    roundTree(node->left, k, ind);
    node->ind = num + 1;
    num++;
    if (node->key == k) *ind = node->ind;
    roundTree(node->right, k, ind);
}

template<typename V, typename T>
int BST<V, T>::getStat() {
    int tmp = stat;
    stat = 0;
    return tmp;
}


template
class BST<int, int>;

template
class BST<unsigned long long, int>;
