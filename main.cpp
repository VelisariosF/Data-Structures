#include <iostream>
#include <fstream>
#include <chrono>
#include "AVLTree\AvlTree.h"

#include "BSTree\BinarySearchTree.h"

int main(){
    AvlTree t;
    BinarySearchTree b;

     
    ifstream f;
    string word;
    f.open("words.txt", ios::in);
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
   
    /* chrono::steady_clock::time_point begin = chrono::steady_clock::now();
     t.search("The");
     chrono::steady_clock::time_point end = chrono::steady_clock::now();
     cout << "Avl search Time difference = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "microseconds" << endl;

      chrono::steady_clock::time_point start = chrono::steady_clock::now();
     b.search("The");
     chrono::steady_clock::time_point endd = chrono::steady_clock::now();
     cout << "BstTree search Time difference = " << chrono::duration_cast<chrono::microseconds>(endd - start).count() << "microseconds" << endl;*/
     f.open("words.txt", ios::in);
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


  return 0;

}