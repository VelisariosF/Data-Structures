#pragma once
#include <iostream>
#include "math.h"
using namespace std;
/*
  Τhis class reprsents a tree node
*/
class avl_node{
    public:
       avl_node();//Empty constructor
       //This constructor takes as paramerter the left child right child, string, appearances of the word
       //the height and the balance factor of the node
       avl_node(avl_node* l, avl_node* r, string aWord, int aps, int h, int bf){
           left = l;
           right = r;
           word = aWord;
           appearances = aps;
           height = h;
           balanceFactor = bf;
       }
       string word;
       int appearances;
       int height;
       int balanceFactor;
       avl_node *left;
       avl_node *right;
};

/*
This class represents the tree itself

*/
class AvlTree{
     private:
       avl_node *root;//root of the tree
       avl_node* insertion(avl_node* root, string aWord);//insert metod that gets as parameter the root and the 
       //word to  be inserted
       avl_node* deletion(avl_node* root, string aWord);//deletion function
       bool search(avl_node* root, string aWord);//search function
       int getHeight(avl_node* root);//this funch returns the height of the tree
       int getBfactor(avl_node* root);//this returns the balance factor of the tree
       avl_node* rightRotation(avl_node* root);//with this funch right rotation is performed
       avl_node* leftRotation(avl_node* root);//with this funch left rotation is performed
       avl_node* leftLeftCase(avl_node* root);//with this funch is used in case we have a left left case 
       //for the tree rotation
       avl_node* rightRightCase(avl_node* root);//with this funch is used in case we have a right right case 
       //for the tree rotation
       avl_node* leftRightCase(avl_node* root);//with this funch is used in case we have a left right case 
       //for the tree rotation
       avl_node* rightLeftCase(avl_node* root);//with this funch is used in case we have a right left case 
       //for the tree rotation
       avl_node* getBalanced(avl_node* root);//this funch is used to balance the tree
       void  updateAvl_node(avl_node* root);//this funch is used to update the childs, height and balance factor of the node
       avl_node* findMin(avl_node* root);//this returns the node with the min value that belongs to a tree
       //or subtree with the specific root node
       void inOrder(avl_node* root);//print nodes using inOrder
       void preOrder(avl_node* root);//print nodes using preOrder
       void postOrder(avl_node* root);//print nodes using postOrder
       void print(avl_node* root, string aWord);//print words that have been searched from the avl tree
    public:
      AvlTree();

      bool insertion(string aWord);//insert metod that gets as parameter the word to  be inserted
      bool deletion(string aWord);//deletion funch that gets as a pram the word to be deleted
      bool search(string word);//this func takes as a param the word to be searched
      void inOrder();//print nodes using inOrder
      void preOrder();//print nodes using preOrder
      void postOrder();//print nodes using postOrder
       void print(string aWord);//print words that have been searched from the avl tree
};













