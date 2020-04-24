#include <iostream>
#include <string>
using namespace std;

class BinarySearchTree
{
    string word;
    int appearances;
    BinarySearchTree *left, *right;

    public:

     // Default constructor.
        BinarySearchTree();

    // Parameterized constructor.
       BinarySearchTree(string aWord, int aps);

    // Insert function.
        BinarySearchTree* Insert(BinarySearchTree*, string aWord, int aps);

    // Inorder traversal.
        void Inorder(BinarySearchTree*);
};
