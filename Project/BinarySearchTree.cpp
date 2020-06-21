#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(){//This contructor initializes the root of the tree to a null value
    root = NULL;
}
//insert metod that gets as parameter the word to  be inserted
bool BinarySearchTree:: insertion(string aWord){

         root = insertion(root, aWord);

     return true;
}
//insert metod that gets as parameter the root and the 
 //word to  be inserted
bst_node* BinarySearchTree::insertion(bst_node* root, string aWord){

    if(!root){

        root = new bst_node(NULL, NULL, aWord, 1);
        return root;
    }else{

        if(aWord.compare(root->word) < 0){

            root->left = insertion(root->left, aWord);
        }else if(aWord.compare(root ->word) > 0) {

            root->right = insertion(root->right, aWord);
        }else{
            //if the word exists just increase its appearances
            root->appearances++;
        }
    }

    return root;
}
//deletion funch that gets as a pram the word to be deleted
bool BinarySearchTree::deletion(string aWord){
    if(search(aWord)){
        root = deletion(root, aWord);
        return true;
    }
    return false;
}

//deletion function
bst_node* BinarySearchTree::deletion(bst_node* root, string aWord){
 bst_node* temp;
    if(!root){//if the tree is empty just return NULL
        return NULL;
    }else{
        //Try to find the word 
        if(aWord.compare(root->word) < 0){
            root ->left = deletion(root->left, aWord);
        }else if(aWord.compare(root->word) > 0){
            root -> right = deletion(root->right, aWord);
        }else{
            if((root->left == NULL) ||  (root->right == NULL)){  
                            bst_node *temp = root->left ? root->left : root->right;  
  
                         // No child case  
                          if (temp == NULL){  
                               temp = root;  
                               root = NULL;  
                         }else // One child case  
                             *root = *temp; // Copy the contents of  
                           // the non-empty child  
                         delete temp;  
             }else{  
                      // bst_node with two children: Get the inorder  
                         // successor (smallest in the right subtree)  
                       bst_node* temp = findMin(root->right);  
  
                      // Copy the inorder successor's  
                     // data to this bst_node  
                      root->word = temp->word;  
   
                    // Delete the inorder successor  
                     root->right = deletion(root->right, temp->word);  
             }  
          }  
  
              // If the tree had only one bst_node 
              // then return  
            if (root == NULL)  
                return root; 
            
        return root;
           
     }
             
    }


//this returns the node with the min value that belongs to a tree
//or subtree with the specific root node
bst_node* BinarySearchTree::findMin(bst_node* root){
    bst_node* current = root;
    while(current->left){
        current = current->left;
    }

    return current;
}

//this func takes as a param the word to be searched
bool BinarySearchTree:: search(string aWord){
     return search(root, aWord);
}
//search function
bool BinarySearchTree:: search(bst_node* root, string aWord){
    if(!root){
        return false;
    }else{
        if(root->word.compare(aWord)){
          return true;
        }else if(aWord.compare(root->word) < 0){
            return search(root->left, aWord);
        }else if(aWord.compare(root->word) > 0){
            return search(root->right, aWord);
        }
    }
}





//print nodes using inOrder
void BinarySearchTree::inOrder(){
    inOrder(root);
}

void BinarySearchTree::inOrder(bst_node* root){
    if(!root){
        return;
    }else{
        inOrder(root->left);
        cout << root->word << ": " << root->appearances << endl;
        inOrder(root->right);
    }
}
//print nodes using preOrder
void BinarySearchTree::preOrder(){
    preOrder(root);
}

void BinarySearchTree::preOrder(bst_node* root){
    if(!root){
        return;
    }else{
        cout << root->word << ": " << root->appearances << endl;
        inOrder(root->left);
        inOrder(root->right);
    }
}
//print nodes using postOrder
void BinarySearchTree::postOrder(){
    postOrder(root);
}

void BinarySearchTree::postOrder(bst_node* root){
    if(!root){
        return;
    }else{
        inOrder(root->left);
        inOrder(root->right);
         cout << root->word << ": " << root->appearances << endl;
    }
}
