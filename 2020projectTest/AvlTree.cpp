#include "AvlTree.h"

AvlTree::AvlTree()
{
    root = NULL;
}


int AvlTree::getHeight(node2* root){
    if(!root)
      return 0;
    return root->height;
}

int AvlTree:: getBfactor(node2* root){
    return root->balanceFactor;
}

node2* AvlTree:: rightRotation(node2* root){
    node2* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updatenode2(root);
    updatenode2(temp);
    return temp;
}

node2* AvlTree:: leftRotation(node2* root){
    node2* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updatenode2(root);
    updatenode2(temp);
    return temp;
}

node2* AvlTree:: leftLeftCase(node2* root){
    return rightRotation(root);
}

node2* AvlTree:: rightRightCase(node2* root){
     return leftRotation(root);
}

node2* AvlTree:: leftRightCase(node2* root){
    root->left = leftRotation(root->left);
    return leftLeftCase(root);
}

node2* AvlTree:: rightLeftCase(node2* root){
    root->right = rightRotation(root->right);
    return rightRightCase(root);
}

node2* AvlTree:: getBalanced(node2* root){
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

void AvlTree:: updatenode2(node2* root){
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

bool AvlTree:: search(node2* root, string aWord){
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

node2* AvlTree::insertion(node2* root, string aWord){

    if(!root){

        root = new node2(NULL, NULL, aWord, 1, 0, 0);
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

    updatenode2(root);
    return getBalanced(root);
}


bool AvlTree::deletion(string aWord){
    if(search(aWord)){
        root = deletion(root, aWord);
        return true;
    }
    return false;
}


node2* AvlTree::deletion(node2* root, string aWord){
    node2* temp;
    if(!root){
        return NULL;
    }else{

        if(aWord.compare(root->word) < 0){
            root ->left = deletion(root->left, aWord);
        }else if(aWord.compare(root->word) > 0){
            root -> right = deletion(root->right, aWord);
        }else{
            if((root->left == NULL) ||  (root->right == NULL)){
                            node2 *temp = root->left ? root->left : root->right;

                         // No child case
                          if (temp == NULL){
                               temp = root;
                               root = NULL;
                         }else // One child case
                             *root = *temp; // Copy the contents of
                           // the non-empty child
                         delete temp;
             }else{
                      // node2 with two children: Get the inorder
                         // successor (smallest in the right subtree)
                       node2* temp = findMin(root->right);

                      // Copy the inorder successor's
                     // data to this node2
                      root->word = temp->word;

                    // Delete the inorder successor
                     root->right = deletion(root->right, temp->word);
             }
          }

              // If the tree had only one node2
              // then return
            if (root == NULL)
                return root;
            else{
               updatenode2(root);
               return getBalanced(root);
            }

     }

 }







node2* AvlTree::findMin(node2* root){
    node2* current = root;
    while(current->left){
        current = current->left;
    }

    return current;
}


void AvlTree::inOrder(){
    inOrder(root);
}

void AvlTree::inOrder(node2* root){
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

void AvlTree::preOrder(node2* root){
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

void AvlTree::postOrder(node2* root){
    if(!root){
        return;
    }else{
        inOrder(root->left);
        inOrder(root->right);
         cout << root->word << ": " << root->appearances << endl;
    }
}


