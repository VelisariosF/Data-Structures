#include <iostream>
#include <string>
using namespace std;
/* This class implements a Binary Search Tree
*/


class B
{
    //Each node of the tree contains a word and the number of appearances inside the tree
    string word;//This variable represents the specfic word

    int appearances;//This represents how many times this word appeared inside the tree
    B *left, *right; //Each node of the tree has a left and a right child which is also a 
                                    //binary tree.

    public:

     // Default constructor.
        B();
        
        B(string aWord);
   
    //search function
       bool search(string aWord);
   

    // Insert function.
        B* insert(B*, string aWord);
        void insertion(string aWord);

    // Delete function
        B* deletion(B*, string aWord);
    // Inorder traversal.
        void inorder();
        void inorder(B*);
    //PreOrder traversal
        void preOrder(B*);
    //PostOrder traversal
        void postOrder(B*);

    //This function returns the minimum node inside the binary tree with root equal to the parameter
        B* minValueNode(B *root);
};


B :: B() {
    
    this->left = NULL;
    this-> right = NULL;
}

// Parameterized Constructor definition.
B:: B(string aWord){
      this -> word = aWord;
      this -> appearances++;
      this -> left = NULL;
      this -> right = NULL;
}

bool B:: search(string aWord){
    B *root = this;
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

void B:: insertion(string aWord){
      B *root = this;
   while(root){
       if(aWord > root -> word){
           root = root -> right;
       }else if(aWord < root -> word){
           root = root -> left;
       }else{
           root->appearances++;
           this->left = root->left;
          this->right = root->right;
         this->appearances= root->appearances;
         this->word = root->word;
         return;
       }
   }
     
     root = this->insert(this, aWord);
     this->left = root->left;
     this->right = root->right;
     this->appearances= root->appearances;
     this->word = root->word;
     return;
     

}

// Insert function definition.
B* B:: insert(B *root, string aWord)
{
     

    if(root == NULL)
    {
         root = new B(aWord);
         
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
    return root;
}

// Delete function
B* B:: deletion(B* root, string aWord){
   
    
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
              B *temp = root->left;
              delete root;
              return temp;
          }else if(root->left == NULL && root->right != NULL){
              B *temp = root->right;
              delete root;
              return temp;
          }else{
              B *temp = minValueNode(root->right), *t = minValueNode(root->right);
              root->word = temp->word;
              root->appearances = temp->appearances;
              root->right = deletion(root-> right, temp->word);
          }

     }

     return root;
    
   
    

}

B* B::minValueNode(B *root)
{
    while (root->left != NULL)
    {
         root = root->left;
    }
    return root;
}
// Inorder traversal function.
// This gives word in sorted order.
void B:: inorder()
{
    B *root = this;
    if(!root)
    {
        return;
    }
    inorder(root);
}

void B::inorder(B* root){
    if(!root)
    {
        return;
    }
    inorder(root->left);
    cout << "Word:" << root->word << " Appearances:" << root -> appearances << endl;
    inorder(root->right);
}

void B:: preOrder(B *root)
{
    if(!root)
    {
        return;
    }
    cout << "Word:" << root->word << " Appearances:" << root -> appearances << endl;
    inorder(root->left);
    inorder(root->right);
}

void B:: postOrder(B *root)
{
    if(!root)
    {
        return;
    }
   
    inorder(root->left);
    inorder(root->right);
     cout << "Word:" << root->word << " Appearances:" << root -> appearances << endl;
}



