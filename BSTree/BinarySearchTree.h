#include <iostream>
using namespace std;

class node{
    public:
       node();
       node(node* l, node* r, string aWord, int aps){
           left = l;
           right = r;
           word = aWord;
           appearances = aps;
       }
       string word;
       int appearances;
       node *left;
       node *right;
};

class BinarySearchTree{
    private:
       node *root;
       node* insertion(node* root, string aWord);
       node* deletion(node* root, string aWord);
       bool exists(node* root, string aWord);
       node* findMin(node* root);
       void inorder(node* root);
   public:
    BinarySearchTree(){
        root = NULL;
    }
    
    bool insertion(string aWord);
    bool deletion(string aWord);
    bool exists(string word);
    void inorder();
};

bool BinarySearchTree:: insertion(string aWord){
     if(!exists(aWord)){
         root = insertion(root, aWord);
         return true;
     }
     return false;
}

node* BinarySearchTree::insertion(node* root, string aWord){
    
    if(!root){
        root = new node(NULL, NULL, aWord, 1);
        return root;
    }else{

        if(aWord < root->word){
            root->left = insertion(root->left, aWord);
        }else{
            root->right = insertion(root->right, aWord);
        }
    }

    return root;
}

bool BinarySearchTree::deletion(string aWord){
    if(exists(aWord)){
        root = deletion(root, aWord);
        return true;
    }
    return false;
}


node* BinarySearchTree::deletion(node* root, string aWord){
    if(!root){
        return NULL;
    }else{
        if(aWord < root->word){
            root->left = deletion(root->left, aWord);
        }else if(aWord > root->word){
            root->right = deletion(root->right, aWord);
        }else{

           if(root->left == NULL && root->right != NULL){
                 node* temp = root->right;
                  root = temp;
                   delete temp;
           }else if(root->right == NULL && root->left != NULL){
                 node* temp = root->left;
                 root = temp;
                 delete temp;
           }else{
                 node* temp = findMin(root->right);
                 
                 root->word = temp->word;
                 root->appearances = temp->appearances;
                 root->right = deletion(root->right, temp->word);
           }
           

        }
    }
    return root;
}

node* BinarySearchTree::findMin(node* root){
    node* current = root;
    while(current->left){
        current = current->left;
    }

    return current;
}


bool BinarySearchTree:: exists(string aWord){
     return exists(root, aWord);
}

bool BinarySearchTree:: exists(node* root, string aWord){
    if(!root){
        return false;
    }else{
        if(root->word == aWord){
          root->appearances++;
          return true;
        }else if(aWord < root->word){
            return exists(root->left, aWord);
        }else if(aWord > root->word){
            return exists(root->right, aWord);
        }
    }   
}






void BinarySearchTree::inorder(){
    inorder(root);
}

void BinarySearchTree::inorder(node* root){
    if(!root){
        return;
    }else{
        inorder(root->left);
        cout << root->word << ": " << root->appearances << endl;
        inorder(root->right);
    }
}