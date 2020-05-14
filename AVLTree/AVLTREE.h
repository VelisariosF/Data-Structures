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
    public:
      AvlTree(){
        root = NULL;
      }
     
      bool insertion(string aWord);
      bool deletion(string aWord);
      bool search(string word);
      void inOrder();
      void preOrder();
      void postOrder();
};




int AvlTree:: getHeight(avl_node* root){
    if(!root)
      return 0;
    return root->height;
}

int AvlTree:: getBfactor(avl_node* root){
    return root->balanceFactor;
}

avl_node* AvlTree:: rightRotation(avl_node* root){
    avl_node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateAvl_node(root);
    updateAvl_node(temp);
    return temp;
}

avl_node* AvlTree:: leftRotation(avl_node* root){
    avl_node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateAvl_node(root);
    updateAvl_node(temp);
    return temp;
}

avl_node* AvlTree:: leftLeftCase(avl_node* root){
    return rightRotation(root);
}

avl_node* AvlTree:: rightRightCase(avl_node* root){
     return leftRotation(root);
}

avl_node* AvlTree:: leftRightCase(avl_node* root){
    root->left = leftRotation(root->left);
    return leftLeftCase(root);
}

avl_node* AvlTree:: rightLeftCase(avl_node* root){
    root->right = rightRotation(root->right);
    return rightRightCase(root);
}

avl_node* AvlTree:: getBalanced(avl_node* root){
    if(getBfactor(root) == 2){
            if(getBfactor(root->right) >= 0)
            {
                   return rightRightCase(root);
            }
            else
            {
                return rightLeftCase(root);
            }

        }

        if(getBfactor(root) == -2)
        {
            if(getBfactor(root->left) >= 0)
            {
                return leftRightCase(root);
            }
            else
            {
                return leftLeftCase(root);
            }
        }
    return root;
         
}

void AvlTree:: updateAvl_node(avl_node* root){
    int leftChildHeight = -1, rightChildHeight = -1;
    if(root->left != NULL){
        leftChildHeight = getHeight(root->left);
    }

    if(root->right != NULL){
        rightChildHeight = getHeight(root->right);
    }
    
    root->height = max(leftChildHeight, rightChildHeight);
    root->balanceFactor = rightChildHeight - leftChildHeight;
}

bool AvlTree:: search(string aWord){
    return search(root, aWord);
}

bool AvlTree:: search(avl_node* root, string aWord){
    if(!root){
        return false;
    }else{
        if(root->word == aWord){
          return true;
        }else if(aWord.compare(root->word) < 0){
            return search(root->left, aWord);
        }else if(aWord.compare(root->word) > 0){
            return search(root->right, aWord);
        }
    }   
}

bool AvlTree:: insertion(string aWord){
     
         root = insertion(root, aWord);
    
     return true;
}

avl_node* AvlTree::insertion(avl_node* root, string aWord){
    
    if(!root){
        
        root = new avl_node(NULL, NULL, aWord, 1, 0, 0);
        return root;
    }else{

        if(aWord.compare(root->word) < 0){
            root->left = insertion(root->left, aWord);
           
        }else if(aWord.compare(root ->word) > 0) {
            root->right = insertion(root->right, aWord);
            
        }else{
            root->appearances++;
        }
    }
    
    updateAvl_node(root);
    return getBalanced(root);
}


bool AvlTree::deletion(string aWord){
    if(search(aWord)){
        root = deletion(root, aWord);
        return true;
    }
    return false;
}


avl_node* AvlTree::deletion(avl_node* root, string aWord){
    avl_node* temp;
    if(!root){
        return NULL;
    }else{

        if(aWord.compare(root->word) < 0){
            root ->left = deletion(root->left, aWord);
        }else if(aWord.compare(root->word) > 0){
            root -> right = deletion(root->right, aWord);
        }else{
            if((root->left == NULL) ||  (root->right == NULL)){  
                            avl_node *temp = root->left ? root->left : root->right;  
  
                         // No child case  
                          if (temp == NULL){  
                               temp = root;  
                               root = NULL;  
                         }else // One child case  
                             *root = *temp; // Copy the contents of  
                           // the non-empty child  
                         delete temp;  
             }else{  
                      // avl_node with two children: Get the inorder  
                         // successor (smallest in the right subtree)  
                       avl_node* temp = findMin(root->right);  
  
                      // Copy the inorder successor's  
                     // data to this avl_node  
                      root->word = temp->word;  
   
                    // Delete the inorder successor  
                     root->right = deletion(root->right, temp->word);  
             }  
          }  
  
              // If the tree had only one avl_node 
              // then return  
            if (root == NULL)  
                return root; 
            else{
               updateAvl_node(root);
               return getBalanced(root);
            } 
           
     }
             
 }


 
    
    
 

avl_node* AvlTree::findMin(avl_node* root){
    avl_node* current = root;
    while(current->left){
        current = current->left;
    }

    return current;
}


void AvlTree::inOrder(){
    inOrder(root);
}

void AvlTree::inOrder(avl_node* root){
    if(!root){
        return;
    }else{
        inOrder(root->left);
        cout << root->word << ": " << root->appearances << endl;
        inOrder(root->right);
    }
}

void AvlTree::preOrder(){
    preOrder(root);
}

void AvlTree::preOrder(avl_node* root){
    if(!root){
        return;
    }else{
        cout << root->word << ": " << root->appearances << endl;
        inOrder(root->left);
        inOrder(root->right);
    }
}

void AvlTree::postOrder(){
    postOrder(root);
}

void AvlTree::postOrder(avl_node* root){
    if(!root){
        return;
    }else{
        inOrder(root->left);
        inOrder(root->right);
         cout << root->word << ": " << root->appearances << endl;
    }
}









