#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree b, *root = NULL;
    root = b.Insert(root, "velisarios", 20);
    b.Insert(root, "dog", 14);
    b.Insert(root, "table", 45);
    b.Insert(root, "this", 30);
    b.Insert(root, "that", 90);

    b.Inorder(root);
    return 0;
}
