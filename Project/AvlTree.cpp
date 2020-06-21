#include "AvlTree.h"

AvlTree::AvlTree(){//This contructor initializes the root of the tree to a null value
        root = NULL;
}
//this funch returns the height of the tree
int AvlTree::getHeight(avl_node* root){
    if(!root)
      return 0;
    return root->height;
}
//this returns the balance factor of the tree
int AvlTree::getBfactor(avl_node* root){
    return root->balanceFactor;
}
//with this funch right rotation is performed
avl_node* AvlTree:: rightRotation(avl_node* root){
    avl_node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateAvl_node(root);
    updateAvl_node(temp);
    return temp;
}
//with this funch left rotation is performed
avl_node* AvlTree:: leftRotation(avl_node* root){
    avl_node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateAvl_node(root);
    updateAvl_node(temp);
    return temp;
}
//with this funch is used in case we have a left left case 
//for the tree rotation
avl_node* AvlTree:: leftLeftCase(avl_node* root){
    return rightRotation(root);
}
//with this funch is used in case we have a right right case 
 //for the tree rotation
avl_node* AvlTree:: rightRightCase(avl_node* root){
     return leftRotation(root);
}
//with this funch is used in case we have a left right case 
//for the tree rotation
avl_node* AvlTree:: leftRightCase(avl_node* root){
    root->left = leftRotation(root->left);
    return leftLeftCase(root);
}
//with this funch is used in case we have a right left case 
//for the tree rotation
avl_node* AvlTree:: rightLeftCase(avl_node* root){
    root->right = rightRotation(root->right);
    return rightRightCase(root);
}
//this funch is used to balance the tree
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
//this funch is used to update the childs, height and balance factor of the node
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
//this returns the node with the min value that belongs to a tree
bool AvlTree:: search(string aWord){
    return search(root, aWord);
}
//this func takes as a param the root of the tree the word to be searched
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
//insert metod that gets as parameter the word to  be inserted
bool AvlTree:: insertion(string aWord){

         root = insertion(root, aWord);

     return true;
}
//insert metod that gets as parameter the root and the 
 //word to  be inserted
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

//deletion funch that gets as a pram the word to be deleted
bool AvlTree::deletion(string aWord){
    if(search(aWord)){
        root = deletion(root, aWord);
        return true;
    }
    return false;
}

//deletion function
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






//this returns the node with the min value that belongs to a tree
//or subtree with the specific root node
avl_node* AvlTree::findMin(avl_node* root){
    avl_node* current = root;
    while(current->left){
        current = current->left;
    }

    return current;
}

//print nodes using inOrder
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
//print nodes using preOrder
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
//print nodes using postOrder
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

void AvlTree::print(string aWord){
     print(root, aWord);
}

void AvlTree::print(avl_node* root, string aWord){
     if(root->word == aWord){
           cout << root->word << ": " << root->appearances << endl;
        }else if(aWord.compare(root->word) < 0){
            return print(root->left, aWord);
        }else if(aWord.compare(root->word) > 0){
            return print(root->right, aWord);
        }
}
