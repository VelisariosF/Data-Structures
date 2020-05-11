#include <iostream>
#include <fstream>
#include "AvlTree.h"
#include "BinarySearchTree.h"

int main(){
    AvlTree t;
    BinarySearchTree b;


    ifstream f;
    string word;
    f.open("sub.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          t.insertion(word);
          b.insertion(word);
      }
       cout << "insertion completed" << endl;
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }


     f.open("sub.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
        if(b.search(word)){
            t.deletion(word);
          b.deletion(word);
        }

      }
    cout << "deletion completed" << endl;
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }



}
