#pragma once
#include <iostream>
using namespace std;

class bst_node{
    public:
       bst_node();
       bst_node(bst_node* l, bst_node* r, string aWord, int aps){
           left = l;
           right = r;
           word = aWord;
           appearances = aps;
       }
       string word;
       int appearances;
       bst_node *left;
       bst_node *right;
};

class BinarySearchTree{
    private:
       bst_node *root;
       bst_node* insertion(bst_node* root, string aWord);
       bst_node* deletion(bst_node* root, string aWord);
       bool search(bst_node* root, string aWord);
       bst_node* findMin(bst_node* root);
       void inOrder(bst_node* root);
       void preOrder(bst_node* root);
       void postOrder(bst_node* root);
   public:
    BinarySearchTree();
    bool insertion(string aWord);
    bool deletion(string aWord);
    bool search(string word);
    void inOrder();
    void preOrder();
    void postOrder();
};



