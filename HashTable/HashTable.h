#include <iostream>
#include <string>
using namespace std;

class Str{
    public:
       Str();
       Str(string aWord, int aps){
            word = aWord;
            appearances = aps;
        }
       string word;
       int appearances;
       
};

class hash_node{
    public:
        Str value;
         int key;
          hash_node(int key, Str value) 
          { 
             this->value = value; 
             this->key = key; 
          } 
};

class HashTable{
    private:
      hash_node **array;
      int capacity;
      int size;

    public:
      HashTable();
      int hashCode(int key);
      void insert(string value);
      bool search(int key);
      
};

HashTable::HashTable(){
        capacity = 20; 
        size=0; 
        array = new hash_node*[capacity]; 
          
        //Initialise all elements of array as NULL 
        for(int i=0 ; i < capacity ; i++) 
            array[i] = NULL; 
          
}

int HashTable::hashCode(int key){
    return key%capacity;
}

bool HashTable::search(int key){
    int hashIndex = hashCode(key);
    int counter  = 0;
     while(array[hashIndex] != NULL) 
        {   
             int counter =0; 
             if(counter++>capacity)  //to avoid infinite loop 
                return false;         
            //if node found return its value 
            if(array[hashIndex]->key == key) 
                return true; 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //If not found return null 
        return false; 
}

void HashTable::insert(string aWord){
    

}
