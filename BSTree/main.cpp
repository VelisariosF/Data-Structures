#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
    BinarySearchTree b, *root = NULL;
     ifstream f;
    string word;
/*    f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          b.insert(root, word);
      }
    }else{
        cerr << "Coud not open the file" << endl;
    }*/

    root =b.insert(root, "vel");
    root =b.insert(root, "vel");
    
    root =b.insert(root, "vel");
    root = b.insert(root, "dfad");
    b.inorder(root);


    return 0;
}
