#include "BinarySearchTree.h"

BinarySearchTree:: BinarySearchTree() {
    word = "";
    appearances = 0;
    left = NULL;
    right = NULL;
}

// Parameterized Constructor definition.
BinarySearchTree:: BinarySearchTree(string aWord, int aps)
{
    word = aWord;
    appearances = aps;
    left = right = NULL;
}

// Insert function definition.
BinarySearchTree* BinarySearchTree:: Insert(BinarySearchTree *root, string aWord, int aps)
{
    if(!root)
    {
        // Insert the first node, if root is NULL.
        return new BinarySearchTree(aWord, aps);
    }

    // Insert word.
    if(aWord > root->word)
    {
        // Insert right node word, if the 'value'
        // to be inserted is greater than 'root' node word.

        // Process right nodes.
        root->right = Insert(root->right, aWord, aps);
    }
    else
    {
        // Insert left node word, if the 'value'
        // to be inserted is greater than 'root' node word.

        // Process left nodes.
        root->left = Insert(root->left, aWord, aps);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function.
// This gives word in sorted order.
void BinarySearchTree:: Inorder(BinarySearchTree *root)
{
    if(!root)
    {
        return;
    }
    cout << "Word:" << root->word << " Appearances:" << root -> appearances << endl;
    Inorder(root->left);

    Inorder(root->right);
}
