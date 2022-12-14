#include "menu.h"

void textMenu() {
    cout << endl
         << "*********** Operation menu ***********" << endl
         << "1  - Request tree size" << endl
         << "2  - Clear the tree" << endl
         << "3  - Check tree for empty" << endl
         << "4  - Read value by key in tree" << endl
         << "5  - Change value by key in tree" << endl
         << "6  - Insert value" << endl
         << "7  - Delete value" << endl
         << "8  - List of keys in tree" << endl
         << "9  - Get sequence number by key" << endl
         << "10 - Request statistics" << endl
         << "11 - Print tree structure" << endl
         << "12 - Forward iterator operation" << endl
         << "13 - Reverse iterator operation" << endl
         << "14 - Random tree testing" << endl
         << "15 - Degenerate tree testing" << endl
         << "0  - Exit" << endl;
}

void forwardIteratorMenu(BST<int, int> &tree) {
    int choice = -1;
    TreeNode<int, int> *tmp = nullptr;
    ForwardIterator<int, int> it = ForwardIterator(tmp, -2);
    ForwardIterator<int, int> it1 = ForwardIterator(tmp, -2);
    it = tree.begin();
    while (choice != 0) {
        cout << "_____Choose what you want to do:" << endl
             << "1 - Set iterator to the begin" << endl
             << "2 - Set iterator to the end" << endl
             << "3 - Get value by iterator" << endl
             << "4 - Change value by iterator" << endl
             << "5 - Move to next value" << endl
             << "6 - Move to prev value" << endl
             << "7 - Show all values" << endl
             << "0 - Go back" << endl;
        cout << "Enter number: ";
        cin >> choice;
        switch (choice) {
            case 1:
                it = tree.begin();
                break;
            case 2:
                it = tree.end();
                break;
            case 3:
                if (it.getStatus() > 0) {
                    cout << "Value: " << *it << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 4:
                if (it.getStatus() > 0) {
                    int val;
                    cout << "Enter value: ";
                    cin >> val;
                    *it = val;
                    cout << "Changed" << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 5:
                if (it.getStatus() > 0 && it++ != tree.end()) {
                    cout << "Value: " << *it << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 6:
                if (it.getStatus() > 0 && it-- != tree.end()) {
                    cout << "Value: " << *it << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 7:
                for (it1 = tree.begin(); it1 != tree.end(); it1++) {
                    cout << *it1 << endl;
                }
                cout << endl;
                break;
            default:
                break;
        }
    }
}

void reverseIteratorMenu(BST<int, int> &tree) {
    int choice = -1;
    TreeNode<int, int> *tmp = nullptr;
    ReverseIterator<int, int> it = ReverseIterator(tmp, -2);
    ReverseIterator<int, int> it1 = ReverseIterator(tmp, -2);
    it = tree.rbegin();
    while (choice != 0) {
        cout << "_____Choose what you want to do:" << endl
             << "1 - Set iterator to the begin" << endl
             << "2 - Set iterator to the end" << endl
             << "3 - Get value by iterator" << endl
             << "4 - Change value by iterator" << endl
             << "5 - Move to prev value" << endl
             << "6 - Move to next value" << endl
             << "7 - Show all values" << endl
             << "0 - Go back" << endl;
        cout << "Enter number: ";
        cin >> choice;
        switch (choice) {
            case 1:
                it = tree.rbegin();
                break;
            case 2:
                it = tree.rend();
                break;
            case 3:
                if (it.getStatus() > 0) {
                    cout << "Value: " << *it << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 4:
                if (it.getStatus() > 0) {
                    int val;
                    cout << "Enter value: ";
                    cin >> val;
                    *it = val;
                    cout << "Changed" << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 5:
                if (it.getStatus() > 0 && it++ != tree.rend()) {
                    cout << "Value: " << *it << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 6:
                if (it.getStatus() > 0 && it-- != tree.rend()) {
                    cout << "Value: " << *it << endl;
                } else {
                    cout << "Error. Iterator not set" << endl;
                }
                break;
            case 7:
                for (it1 = tree.rbegin(); it1 != tree.rend(); it1--) {
                    cout << *it1 << endl;
                }
                cout << endl;
                break;
            default:
                break;
        }
    }
}

void insertMenu(BST<int, int> &tree) {
    int choice = -1;
    int len;
    while (choice != 0) {
        cout << "_____Choose what you want to do:" << endl
             << "1 - Fill the tree with random keys and values" << endl
             << "2 - Insert new value with a key" << endl
             << "0 - Go back" << endl;
        cout << "Enter number: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (!tree.isEmpty()) tree.clear();
                cout << "Enter size of tree: ";
                cin >> len;
                srand(time(nullptr));
                for (int i = 0; i < len; i++) {
                    tree.insert(rand() % 100, -50 + rand() % 100);
                }
                cout << "Done" << endl;
                break;
            case 2:
                int val, k;
                cout << "Enter key: ";
                cin >> k;
                cout << "Enter value: ";
                cin >> val;
                tree.insert(k, val);
                cout << "Done" << endl;
                break;
            default:
                break;
        }
    }
}

void menu() {
    int ch = -1;
    BST<int, int> tree;
    while (ch != 0) {
        textMenu();
        cout << endl << "Enter operation number: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Size of tree: " << tree.getSize() << endl;
                break;
            case 2:
                if (tree.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    tree.clear();
                    cout << "Done" << endl;
                }
                break;
            case 3:
                if (tree.isEmpty()) cout << "Tree is empty" << endl;
                else cout << "Tree isn't empty" << endl;
                break;
            case 4:
                if (tree.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    int k;
                    cout << "Enter key: ";
                    cin >> k;
                    if (tree.getElement(k) == -1) cout << "Error. Tree is empty or invalid key" << endl;
                    else cout << "Value of this key: " << tree.getElement(k) << endl;
                }
                break;
            case 5:
                if (tree.isEmpty()) {
                    cout << "Tree is empty" << endl;
                } else {
                    int k, val;
                    cout << "Enter key: ";
                    cin >> k;
                    cout << "Enter value: ";
                    cin >> val;
                    if (tree.changeElement(k, val)) cout << "Done" << endl;
                    else cout << "Error. Tree is empty or invalid key" << endl;
                }
                break;
            case 6:
                insertMenu(tree);
                break;
            case 7:
                int k;
                cout << "Enter key: ";
                cin >> k;
                if (tree.remove(k)) cout << "Done" << endl;
                else cout << "Failed to delete. This value isn't in the tree" << endl;
                break;
            case 8:
                cout << "List of keys: " << endl;
                tree.printKeys();
                break;
            case 9:
                cout << "Enter key: ";
                cin >> k;
                cout << "Sequence number: " << tree.getIndex(k) << endl;
                break;
            case 10:
                cout << "Laboriousness: " << tree.getStat() << endl;
                break;
            case 11:
                tree.printTree();
                break;
            case 12:
                forwardIteratorMenu(tree);
                break;
            case 13:
                reverseIteratorMenu(tree);
                break;
            case 14:
                int len;
                cout << "Enter tree size: ";
                cin >> len;
                test_rand(len);
                break;
            case 15:
                cout << "Enter tree size: ";
                cin >> len;
                test_ord(len);
                break;
            default:
                break;
        }
    }
}