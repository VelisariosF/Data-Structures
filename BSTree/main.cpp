#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
    BinarySearchTree b, *root = NULL;
   
    ifstream f;
    string word;
    f.open("subject.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          b.insertion(word);
      }
       cout << "insertion completed" << endl;
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }


     f.open("subject.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          b.deletion(word);
      }
    cout << "deletion completed" << endl;
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }


    
   
 // cout << "Inorder :" << endl;
  //b.inOrder();

 
  
  
  
    return 0;
}
