#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "AvlTree.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#define setSize 100 //define how many words you want to search
//Main method from which the three data structures operate
int main(){
    srand(time(NULL));

    ifstream f;//represents the input file from which the data will be read
    string word;//word to be inserted, searched or deleted
    int s = 0;//counts how many words the file contains
    f.open("small-file.txt", ios::in);
    //counting the words from the file
    if(f.is_open()){
      while(f >> word){
        s++;

      }
        f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }
   AvlTree t;//this variable represents the avl tree
   BinarySearchTree b;//this variable represents the binary search tree
   HashTable h(s);//this variable represents the hash table
   string setOfWords[setSize];//set of words to be searched from the data structures 
   int i = 0;
   int randomNumber = rand() % s + 1;
   //reeading the words from the file
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
       //in this for loop the total time that was needed for the binary search tree to search all the words from the 
       //set of words
      for(int i = 0; i < setSize; i++){
           chrono::steady_clock::time_point bsTreebegin = chrono::steady_clock::now();
          b.search(setOfWords[i]);
           chrono::steady_clock::time_point bsTreeend = chrono::steady_clock::now();
           int timetaken = chrono::duration_cast<chrono::microseconds>(bsTreeend - bsTreebegin).count();
          bsTreeTime += timetaken;
      }
        //in this for loop the total time that was needed for the avl tree to search all the words from the 
       //set of words
      for(int i = 0; i < setSize; i++){
           chrono::steady_clock::time_point avlbegin = chrono::steady_clock::now();
          t.search(setOfWords[i]);
           chrono::steady_clock::time_point avlend = chrono::steady_clock::now();
           int timetaken = chrono::duration_cast<chrono::microseconds>(avlend - avlbegin).count();
          avlTreeTime += timetaken;
      }
       
        //in this for loop the total time that was needed for the hash table to search all the words from the 
       //set of words
      for(int i = 0; i < setSize; i++){
           chrono::steady_clock::time_point hashbegin = chrono::steady_clock::now();
          h.search(setOfWords[i]);
           chrono::steady_clock::time_point hashend = chrono::steady_clock::now();
           int timetaken = chrono::duration_cast<chrono::microseconds>(hashend - hashbegin).count();
          hashTableTime += timetaken;
      }
      //Printing the words tha have been searched from the datastructures
      cout << "<--Words searched-->" << endl;
      for(int i = 0; i < setSize; i++){
          t.print(setOfWords[i]);
      }
     //Printing the total times of each data structure 
     cout << "Avl search Time difference = " << avlTreeTime << " microseconds" << endl;
     cout << "BstTree search Time difference = " << bsTreeTime << " microseconds" <<  endl;
     cout << "HashTable search Time difference = " << hashTableTime << " microseconds" << endl;



  return 0;

}
