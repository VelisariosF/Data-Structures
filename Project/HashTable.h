#pragma once

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


//This class represents a node of the hash table
class Hash_Node{
    public:
        Hash_Node();//empty constructor
        //this node consists of a word and its appearances into the hash table
       Hash_Node(string aWord, int aps){
            word = aWord;
            appearances = aps;
        }
        //copy constriuctor
        Hash_Node(const Hash_Node& hash_Node){
            word = hash_Node.word;
            appearances = hash_Node.appearances;
        }

       string word;//the word of the node
       int appearances;//the aps of the word


};

//this class implements the oppen addresing hash table
class HashTable{
    private:
      Hash_Node **array;//the table it self
      int capacity;//this variable represents  how many elements the hash table can contain
      int size;//this variable represents the size, basically it tells how many words exists inside the hash table
      void insert(Hash_Node* value, int hashIndex);//insert funchion tha gets as parameters the node to
      //be inserted to the table and the pos of the table that will be inserted to
      int search2(string value);//search function that gets as a param the word to be inseted into the hashtable
      int hashFunction(string word);//this funch returns the index of the position in the table into which the
      //word will be inserted to

    public:
      HashTable(int capacity);//this constructor gets as a param the capacity of the table
      void insert(string value);//insertion function
      bool search(string aWord);//search function
      

};



