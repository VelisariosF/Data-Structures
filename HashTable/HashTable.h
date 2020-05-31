#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Str{
    public:
       Str();
       Str(string aWord, int aps){
            word = aWord;
            appearances = aps;
        }

        Str(const Str& str){
            word = str.word;
            appearances = str.appearances;
        }

       string word;
       int appearances;

       bool operator==(Str str){
           if(word.compare(str.word) == 0){
               return true;
           }
           return false;
       }
       
};

class hash_node{
    public:
        Str *key;
          hash_node(Str key) 
          { 
             this->key = new Str(key);
          } 

          hash_node(const hash_node& node){
              this->key = new Str(*node.key);
          }

          
};

class HashTable{
    private:
      hash_node **array;
      int capacity;
      int size;
      void insert(Str value);
      int hashFunction(string word);

    public:
      HashTable();
      void insert(string value);
      bool search(string aWord);
      void print();
      
};

HashTable::HashTable(){
        capacity = 200; 
        size=0; 
        array = new hash_node*[capacity]; 
          
        //Initialise all elements of array as NULL 
        for(int i=0 ; i < capacity ; i++) 
            array[i] = NULL; 
          
}

int HashTable::hashFunction(string key){
    int sum = 0;
    for(int i = 0; i < key.length(); i++){
       sum = 37 * sum + (int)key.at(i);
    }

    sum %= capacity;
    if(sum < 0){
        sum += capacity;
    }
    return sum;
}




bool HashTable::search(string aWord){
    int hashIndex = hashFunction(aWord);
   
    int counter  = 0;
    int i = 1;
     while(array[hashIndex] != NULL) 
        {   
             
             if(counter++>capacity)  //to avoid infinite loop 
                return false;         
            //if node found return true 
            if(array[hashIndex]->key->word.compare(aWord) == 0){
                
               return true;
            } 

            hashIndex = hashIndex + pow(i, 2);  
            i++; 
            hashIndex %= capacity; 
        } 
          
        //If not found return false 
        return false; 
}

void HashTable::insert(string aWord){
     int hashIndex = hashFunction(aWord);
     if(search(aWord)){
           int i = 1;
           while(array[hashIndex] != NULL){   
                    if(array[hashIndex]->key->word.compare(aWord) == 0){
                        array[hashIndex]->key->appearances++;
                     } 
            hashIndex = hashIndex + pow(i, 2);
            i++; 
            hashIndex %= capacity; 
           } 
          
    }else{
        
        if(size < capacity){
           
           Str str(aWord, 1);
           int i = 1;
          hash_node *temp = new hash_node(str);
                       
            while(array[hashIndex] != NULL && array[hashIndex]->key->word.compare(temp->key->word) !=0){
            
             hashIndex = hashIndex + pow(i, 2);
             i++; 
             hashIndex %= capacity; 
           }
          
           if(array[hashIndex] == NULL){
                
                 array[hashIndex] = new hash_node(*temp);
                 size++;
           }
             
          
      
 

        }else if(size == capacity){
            
              hash_node **temp = new hash_node*[capacity + 200];
              for(int i=0 ; i < capacity + 200 ; i++){
                   temp[i] = NULL;
              }

              for(int i=0 ; i < capacity ; i++){
                   temp[i] = array[i];
              }
              delete[] array;
              capacity = capacity + 200;
              array = new hash_node*[capacity]; 
              for(int i=0 ; i < capacity ; i++){
                   array[i] = temp[i];
              }
              delete[] temp;

              Str str(aWord, 1);
              int i = 1;
              hash_node *temp1 = new hash_node(str);
              while(array[hashIndex] != NULL && array[hashIndex]->key->word.compare(temp1->key->word) !=0){
                   hashIndex = hashIndex + pow(i, 2);
                   i++; 
                   hashIndex %= capacity; 
                  
              }
              
              if(array[hashIndex] == NULL){
                 
                  array[hashIndex] = temp1;
                  size++;
               }
             
             return;
            }
    
      }
}



void HashTable::print(){
    for(int i = 0; i < capacity; i++){
        if(array[i] != NULL){
           cout << array[i]->key->word << ": " << array[i]->key->appearances << endl;
        }
        
    }
}