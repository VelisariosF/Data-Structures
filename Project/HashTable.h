#ifndef HASHTALE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;



class Hash_Node{
    public:
        Hash_Node();
       Hash_Node(string aWord, int aps){
            word = aWord;
            appearances = aps;
        }

        Hash_Node(const Hash_Node& hash_Node){
            word = hash_Node.word;
            appearances = hash_Node.appearances;
        }

       string word;
       int appearances;


};

class HashTable{
    private:
      Hash_Node **array;
      int capacity;
      int size;
      void insert(Hash_Node* value, int hashIndex);
      int search2(string value);
      int hashFunction(string word);

    public:
      HashTable(int capacity);
      void insert(string value);
      bool search(string aWord);
      void print();

};
#endif // HASHTALE_H


