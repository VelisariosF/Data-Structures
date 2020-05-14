#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

class node{
    public:
       node();
       node(node* l, node* r, string aWord, int aps){
           left = l;
           right = r;
           word = aWord;
           appearances = aps;
       }
       string word;
       int appearances;
       node *left;
       node *right;
};

class BinarySearchTree{
    private:
       node *root;
       node* insertion(node* root, string aWord);
       node* deletion(node* root, string aWord);
       bool search(node* root, string aWord);
       node* findMin(node* root);
       void inOrder(node* root);
       void preOrder(node* root);
       void postOrder(node* root);
   public:
    BinarySearchTree();

    bool insertion(string aWord);
    bool deletion(string aWord);
    bool search(string word);
    void inOrder();
    void preOrder();
    void postOrder();
};

#endif // BINARYSEARCHTREE_H
