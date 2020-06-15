#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "AvlTree.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#define setSize 1000 //define how many words you want to search

int main(){
    srand(time(NULL));

    ifstream f;
    string word;
    int s = 0;
    f.open("small-file.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
        s++;

      }
        f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }
   AvlTree t;
   BinarySearchTree b;
   HashTable h(s);
   string setOfWords[setSize];
   int i = 0;
   int randomNumber = rand() % s + 1;
    f.open("small-file.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          t.insertion(word);
          b.insertion(word);
          h.insert(word);
          if((rand() % 100 + 1) % 2 == 1 && i < setSize){
            setOfWords[i] = word;
            i++;
          }

      }
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }

      int hashTableTime = 0, avlTreeTime = 0, bsTreeTime = 0;

      for(int i = 0; i < setSize; i++){
           chrono::steady_clock::time_point bsTreebegin = chrono::steady_clock::now();
          b.search(setOfWords[i]);
           chrono::steady_clock::time_point bsTreeend = chrono::steady_clock::now();
           int timetaken = chrono::duration_cast<chrono::microseconds>(bsTreeend - bsTreebegin).count();
          bsTreeTime += timetaken;
      }

      for(int i = 0; i < setSize; i++){
           chrono::steady_clock::time_point avlbegin = chrono::steady_clock::now();
          t.search(setOfWords[i]);
           chrono::steady_clock::time_point avlend = chrono::steady_clock::now();
           int timetaken = chrono::duration_cast<chrono::microseconds>(avlend - avlbegin).count();
          avlTreeTime += timetaken;
      }

      for(int i = 0; i < setSize; i++){
           chrono::steady_clock::time_point hashbegin = chrono::steady_clock::now();
          h.search(setOfWords[i]);
           chrono::steady_clock::time_point hashend = chrono::steady_clock::now();
           int timetaken = chrono::duration_cast<chrono::microseconds>(hashend - hashbegin).count();
          hashTableTime += timetaken;
      }
      cout << "<--Words searched-->" << endl;
      for(int i = 0; i < setSize; i++){
          t.print(setOfWords[i]);
      }

     cout << "Avl search Time difference = " << avlTreeTime << " microseconds" << endl;
     cout << "BstTree search Time difference = " << bsTreeTime << " microseconds" <<  endl;
     cout << "HashTable search Time difference = " << hashTableTime << " microseconds" << endl;



  return 0;

}
