#include <iostream>

using namespace std;


class node{
    public:
       node();
       node(node* l, node* r, string aWord, int aps, int h, int bf){
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
       node *left;
       node *right;
};

class AvlTree{
     private:
       node *root;
       node* insertion(node* root, string aWord);
       node* deletion(node* root, string aWord);
       bool search(node* root, string aWord);
       int getHeight(node* root);
       int getBfactor(node* root);
       node* rightRotation(node* root);
       node* leftRotation(node* root);
       node* leftLeftCase(node* root);
       node* rightRightCase(node* root);
       node* leftRightCase(node* root);
       node* rightLeftCase(node* root);
       node* getBalanced(node* root);
       void  updateNode(node* root);
       node* findMin(node* root);
       void inOrder(node* root);
       void preOrder(node* root);
       void postOrder(node* root);
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




int AvlTree:: getHeight(node* root){
    if(!root)
      return 0;
    return root->height;
}

int AvlTree:: getBfactor(node* root){
    return root->balanceFactor;
}

node* AvlTree:: rightRotation(node* root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateNode(root);
    updateNode(temp);
    return temp;
}

node* AvlTree:: leftRotation(node* root){
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateNode(root);
    updateNode(temp);
    return temp;
}

node* AvlTree:: leftLeftCase(node* root){
    return rightRotation(root);
}

node* AvlTree:: rightRightCase(node* root){
     return leftRotation(root);
}

node* AvlTree:: leftRightCase(node* root){
    root->left = leftRotation(root->left);
    return leftLeftCase(root);
}

node* AvlTree:: rightLeftCase(node* root){
    root->right = rightRotation(root->right);
    return rightRightCase(root);
}

node* AvlTree:: getBalanced(node* root){
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

void AvlTree:: updateNode(node* root){
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

bool AvlTree:: search(node* root, string aWord){
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

node* AvlTree::insertion(node* root, string aWord){
    
    if(!root){
        
        root = new node(NULL, NULL, aWord, 1, 0, 0);
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
    
    updateNode(root);
    return getBalanced(root);
}


bool AvlTree::deletion(string aWord){
    if(search(aWord)){
        root = deletion(root, aWord);
        return true;
    }
    return false;
}


node* AvlTree::deletion(node* root, string aWord){
    node* temp;
    if(!root){
        return NULL;
    }else{

        if(aWord.compare(root->word) < 0){
            root ->left = deletion(root->left, aWord);
        }else if(aWord.compare(root->word) > 0){
            root -> right = deletion(root->right, aWord);
        }else{

            if(!root->left && root->right != NULL){
                 temp = root->right;
                delete root;
                updateNode(temp);
                return getBalanced(temp);
            }else if(!root->right && root->left != NULL){
                 temp = root->left;
                delete root;
                updateNode(temp);
                return getBalanced(temp);
            }else{

                 temp = findMin(root->right);
                root->word = temp->word;
                root->appearances = temp->appearances;
                delete root;
                updateNode(temp);
                return getBalanced(temp);
            }
        }
              updateNode(temp);
                return getBalanced(temp);

    }


 /*if(!root){
        return NULL;
    }else{
          node *p = root, *pp = 0;
              
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
              node *s = p->right, 
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
          node* c;
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
          p = NULL;
          delete p;
          updateNode(root);
          return getBalanced(root);
        }*/
    
    
 }

node* AvlTree::findMin(node* root){
    node* current = root;
    while(current->left){
        current = current->left;
    }

    return current;
}


void AvlTree::inOrder(){
    inOrder(root);
}

void AvlTree::inOrder(node* root){
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

void AvlTree::preOrder(node* root){
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

void AvlTree::postOrder(node* root){
    if(!root){
        return;
    }else{
        inOrder(root->left);
        inOrder(root->right);
         cout << root->word << ": " << root->appearances << endl;
    }
}







