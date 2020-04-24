#include <iostream> 
#include <string>
#include "Node.h"
using namespace std; 
struct node{
    string word;
    int appearances;
    struct node *left, *right; 
};
class BST 
{ 
    node *root; 
    public: 
      
    // Default constructor. 
    BST(); 
      
    // Parameterized constructor. 
    BST(node value); 
      
    // Insert function. 
    node* Insert(node *, node); 
      
    // Inorder traversal. 
    void Inorder(node *); 
  
}; 
  
// Default Constructor definition. 

BST::BST(){
   root  = NULL;
}
  
// Parameterized Constructor definition. 
BST :: BST(node value) 
{ 
    root->appearances = value.appearances;
    root -> word = value.word;
    root ->left = NULL;
    root-> right = NULL;
} 
  
// Insert function definition. 
node* BST :: Insert(node *root, node value) 
{ 
    if(!root) 
    { 
        // Insert the first node, if root is NULL. 
        root = new node;
        root->appearances = value.appearances;
        root->word = value.word;
        root ->left = NULL;
        root ->right = NULL;
        return root; 
    } 
  
    // Insert data. 
    if(value.word > root->word) 
    { 
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 
          
        // Process right nodes. 
        root->right = Insert(root->right, value); 
    } 
    else
    { 
        // Insert left node data, if the 'value'  
        // to be inserted is greater than 'root' node data. 
          
        // Process left nodes. 
        root->left = Insert(root->left, value); 
    } 
      
    // Return 'root' node, after insertion. 
    return root; 
} 
  
// Inorder traversal function. 
// This gives data in sorted order. 
void BST :: Inorder(node *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    Inorder(root->left); 
    cout << root->word << root -> appearances; 
    Inorder(root->right); 
} 


  
// Driver code 
int main() 
{ 
    
    node root, data;
    root.appearances = 2;
    root.word = "zoo";
    BST b(root);
    string word;
    int aprs, i = 0;
    while(i < 5){
        cout << "Give data: ";
        cin >> word;
        cout << "Give aprs: ";
        cin >> aprs;
        data.word = word;
        data.appearances = aprs;
        b.Insert(root, data);
        i++;
    }
    
    //b.Inorder(root); 
    return 0; 
} 
  