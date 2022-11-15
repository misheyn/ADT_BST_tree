#ifndef ADT_BST_TREE_TREENODE_H
#define ADT_BST_TREE_TREENODE_H

template<typename V, typename T>
class TreeNode {
public:
    TreeNode(V k, T val) : right(nullptr), left(nullptr), key(k), data(val), ind(-1) {}

    TreeNode *left;
    TreeNode *right;
    V key;
    T data;
    int ind;

};

#endif //ADT_BST_TREE_TREENODE_H
