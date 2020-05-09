#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
    BinarySearchTree b, *root = NULL;
   
    ifstream f;
    string word;
    f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          b.insertion(word);
      }

      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }


    
   
  cout << "Inorder :" << endl;
  b.inOrder();

  cout << "\n\n\nPreorder :" << endl;
  b.preOrder();

  cout << "\n\n\nPostorder :" << endl;
  b.postOrder();
  
  
  
    return 0;
}
