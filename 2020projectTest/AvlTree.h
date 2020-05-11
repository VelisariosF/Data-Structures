#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>

using namespace std;
class node2{
    public:
       node2();
       node2(node2* l, node2* r, string aWord, int aps, int h, int bf){
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
       node2 *left;
       node2 *right;
};

class AvlTree{
     private:
       node2 *root;
       node2* insertion(node2* root, string aWord);
       node2* deletion(node2* root, string aWord);
       bool search(node2* root, string aWord);
       int getHeight(node2* root);
       int getBfactor(node2* root);
       node2* rightRotation(node2* root);
       node2* leftRotation(node2* root);
       node2* leftLeftCase(node2* root);
       node2* rightRightCase(node2* root);
       node2* leftRightCase(node2* root);
       node2* rightLeftCase(node2* root);
       node2* getBalanced(node2* root);
       void  updatenode2(node2* root);
       node2* findMin(node2* root);
       void inOrder(node2* root);
       void preOrder(node2* root);
       void postOrder(node2* root);
    public:
      AvlTree();

      bool insertion(string aWord);
      bool deletion(string aWord);
      bool search(string word);
      void inOrder();
      void preOrder();
      void postOrder();

};



#endif // AVLTREE_H
