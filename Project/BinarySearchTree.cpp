#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

bool BinarySearchTree:: insertion(string aWord){

         root = insertion(root, aWord);

     return true;
}

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

            root->appearances++;
        }
    }

    return root;
}

bool BinarySearchTree::deletion(string aWord){
    if(search(aWord)){
        root = deletion(root, aWord);
        return true;
    }
    return false;
}


bst_node* BinarySearchTree::deletion(bst_node* root, string aWord){

    if(!root){
        return NULL;
    }else{
          bst_node *p = root, *pp = 0;

          while(p && p->word.compare(aWord) != 0){
              pp = p;
              if(aWord.compare(p->word) < 0){
                  p = p->left;
              }else if(aWord.compare(p->word) > 0){
                  p = p->right;
              }else{
                  cout << "element does not exist" << endl;
              }
          }

          if(p->left && p->right){
              bst_node *s = p->right,
                    *ps = p;

              while(s->left){
                  ps = s;
                  s = s->left;
              }
              p->word = s->word;
              p->appearances = s->appearances;
              p = s;
              pp = ps;

          }
          bst_node* c;
          if(p->left)
              c = p->left;
          else
          {
              c = p->right;
          }

          if(p == root)
             root = c;
          else
          {
              if(p == pp->left)
                  pp->left = c;
              else
              {
                  pp->right = c;
              }

          }
          delete p;

          return root;



        }
    }



bst_node* BinarySearchTree::findMin(bst_node* root){
    bst_node* current = root;
    while(current->left){
        current = current->left;
    }

    return current;
}


bool BinarySearchTree:: search(string aWord){
     return search(root, aWord);
}

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
