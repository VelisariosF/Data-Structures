#include <iostream>
#include <string>
using namespace std;
/* This class implements a Binary Search Tree
*/


class BinarySearchTree
{
    //Each node of the tree contains a word and the number of appearances inside the tree
    string word;//This variable represents the specfic word

    int appearances;//This represents how many times this word appeared inside the tree
    BinarySearchTree *left, *right; //Each node of the tree has a left and a right child which is also a 
                                    //binary tree.

    public:

     // Default constructor.
        BinarySearchTree();
        
        BinarySearchTree(string aWord);
   
    //search function
       bool search(BinarySearchTree*, string aWord);
   

    // Insert function.
        BinarySearchTree* insert(BinarySearchTree*, string aWord);

    // Delete function
        BinarySearchTree* deletion(BinarySearchTree*, string aWord);
    // Inorder traversal.
        void inorder(BinarySearchTree*);
    //PreOrder traversal
        void preOrder(BinarySearchTree*);
    //PostOrder traversal
        void postOrder(BinarySearchTree*);

    //This function returns the minimum node inside the binary tree with root equal to the parameter
        BinarySearchTree* minValueNode(BinarySearchTree *root);
};


BinarySearchTree :: BinarySearchTree() {
    this->word = "";
    this->appearances = 0;
    this->left = NULL;
    this-> right = NULL;
}

// Parameterized Constructor definition.
BinarySearchTree:: BinarySearchTree(string aWord){
      this -> word = aWord;
      this -> appearances++;
      this -> left = NULL;
      this -> right = NULL;
}

bool BinarySearchTree:: search(BinarySearchTree* root, string aWord){
   while(root){
       if(aWord > root -> word){
           root = root -> right;
       }else if(aWord < root -> word){
           root = root -> left;
       }
       else
       {
           return true;
       }
       
   }
    
   return false;
}

// Insert function definition.
BinarySearchTree* BinarySearchTree:: insert(BinarySearchTree *root, string aWord)
{
     while(root){
       if(aWord > root -> word){
           root = root -> right;
       }else if(aWord < root -> word){
           root = root -> left;
       }
       else
       {
          root->appearances++;
          return root;
       }
    }

    if(root == NULL)
    {
         root = new BinarySearchTree(aWord);
         
         return root;
        // Insert the first node, if root is NULL.
        
    }

    // Insert word.
    if(aWord > root->word)
    {
        // Insert right node word, if the 'value'
        // to be inserted is greater than 'root' node word.

        // Process right nodes.
        root->right = insert(root->right, aWord);
    }
    else
    {
        // Insert left node word, if the 'value'
        // to be inserted is greater than 'root' node word.

        // Process left nodes.
        root->left = insert(root->left, aWord);
    }

    // Return 'root' node, after insertion.
    return this;
}

// Delete function
BinarySearchTree* BinarySearchTree:: deletion(BinarySearchTree* root, string aWord){
   
    
     if(root == NULL) 
     {
         return root;
     }
     else if(aWord < root -> word){
         root->left = deletion(root->left, aWord);

     }else if(aWord > root -> word){
         root->right = deletion(root->right, aWord);

     }else{
        
          if(root->left != NULL && root->right == NULL){
              BinarySearchTree *temp = root->left;
              delete root;
              return temp;
          }else if(root->left == NULL && root->right != NULL){
              BinarySearchTree *temp = root->right;
              delete root;
              return temp;
          }else{
              BinarySearchTree *temp = minValueNode(root->right), *t = minValueNode(root->right);
              root->word = temp->word;
              root->appearances = temp->appearances;
              root->right = deletion(root-> right, temp->word);
          }

     }

     return root;
    
   
    

}

BinarySearchTree* BinarySearchTree::minValueNode(BinarySearchTree *root)
{
    while (root->left != NULL)
    {
         root = root->left;
    }
    return root;
}
// Inorder traversal function.
// This gives word in sorted order.
void BinarySearchTree:: inorder(BinarySearchTree *root)
{
    if(!root)
    {
        return;
    }
    
    inorder(root->left);
    cout << "Word:" << root->word << " Appearances:" << root -> appearances << endl;
    inorder(root->right);
}

void BinarySearchTree:: preOrder(BinarySearchTree *root)
{
    if(!root)
    {
        return;
    }
    cout << "Word:" << root->word << " Appearances:" << root -> appearances << endl;
    inorder(root->left);
    inorder(root->right);
}

void BinarySearchTree:: postOrder(BinarySearchTree *root)
{
    if(!root)
    {
        return;
    }
   
    inorder(root->left);
    inorder(root->right);
     cout << "Word:" << root->word << " Appearances:" << root -> appearances << endl;
}



