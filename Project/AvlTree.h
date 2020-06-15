#pragma once
#include <iostream>
#include "math.h"
using namespace std;


class avl_node{
    public:
       avl_node();
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

class AvlTree{
     private:
       avl_node *root;
       avl_node* insertion(avl_node* root, string aWord);
       avl_node* deletion(avl_node* root, string aWord);
       bool search(avl_node* root, string aWord);
       int getHeight(avl_node* root);
       int getBfactor(avl_node* root);
       avl_node* rightRotation(avl_node* root);
       avl_node* leftRotation(avl_node* root);
       avl_node* leftLeftCase(avl_node* root);
       avl_node* rightRightCase(avl_node* root);
       avl_node* leftRightCase(avl_node* root);
       avl_node* rightLeftCase(avl_node* root);
       avl_node* getBalanced(avl_node* root);
       void  updateAvl_node(avl_node* root);
       avl_node* findMin(avl_node* root);
       void inOrder(avl_node* root);
       void preOrder(avl_node* root);
       void postOrder(avl_node* root);
       void print(avl_node* root, string aWord);
    public:
      AvlTree();

      bool insertion(string aWord);
      bool deletion(string aWord);
      bool search(string word);
      void inOrder();
      void preOrder();
      void postOrder();
       void print(string aWord);
};













