#include <iostream>
#include <fstream>
#include <chrono>
#include "AVLTree\AvlTree.h"
#include "HashTable\HashTable.h"
#include "BSTree\BinarySearchTree.h"

int main(){
    AvlTree t;
    BinarySearchTree b;
    HashTable h;
     
    ifstream f;
    string word;
    f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          t.insertion(word);
          b.insertion(word);
          h.insert(word);

      }
       cout << "insertion completed" << endl;
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }
   
     chrono::steady_clock::time_point begin = chrono::steady_clock::now();
     t.search("The");
     chrono::steady_clock::time_point end = chrono::steady_clock::now();
     cout << "Avl search Time difference = " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "microseconds" << endl;
      
      chrono::steady_clock::time_point start = chrono::steady_clock::now();
     b.search("The");
     chrono::steady_clock::time_point endd = chrono::steady_clock::now();
     cout << "BstTree search Time difference = " << chrono::duration_cast<chrono::nanoseconds>(endd - start).count() << "microseconds" << endl;
     

     chrono::steady_clock::time_point startt = chrono::steady_clock::now();
      h.search("The");
       chrono::steady_clock::time_point enddd = chrono::steady_clock::now();
        cout << "HashTable search Time difference = " << chrono::duration_cast<chrono::nanoseconds>(enddd - startt).count() << "microseconds" << endl;

   

  return 0;

}