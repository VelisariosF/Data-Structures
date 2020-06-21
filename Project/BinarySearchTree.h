#pragma once
#include <iostream>
using namespace std;
/*
  Τhis class reprsents a tree node
*/
class bst_node{
    public:
       bst_node();//Empty constructor
       //This constructor takes as paramerter the left child, right child of the node, string, appearances of the word
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
/*
This class represents the tree itself

*/
class BinarySearchTree{
    private:
       bst_node *root;//root of the tree
       bst_node* insertion(bst_node* root, string aWord);//insert metod that gets as parameter the root and the 
       //word to  be inserted
       bst_node* deletion(bst_node* root, string aWord);//deletion function
       bool search(bst_node* root, string aWord);//search function
       bst_node* findMin(bst_node* root);//this returns the node with the min value that belongs to a tree
       //or subtree with the specific root node
       void inOrder(bst_node* root);//print nodes using inOrder
       void preOrder(bst_node* root);//print nodes using preOrder
       void postOrder(bst_node* root);//print nodes using postOrder
   public:
    BinarySearchTree();
    bool insertion(string aWord);//insert metod that gets as parameter the word to  be inserted
    bool deletion(string aWord);//deletion funch that gets as a pram the word to be deleted
    bool search(string word);//this func takes as a param the word to be searched
    void inOrder();//print nodes using inOrder
    void preOrder();//print nodes using preOrder
    void postOrder();//print nodes using postOrder
};



