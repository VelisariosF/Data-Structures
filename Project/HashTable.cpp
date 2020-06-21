#include "HashTable.h"
//this constructor sets the capacity ,the size to zero, and also initializes the elements of the hash table to null
HashTable::HashTable(int capacity){
        this->capacity = capacity;
        size=0;
        array = new Hash_Node*[capacity];

        //Initialise all elements of array as NULL
        for(int i=0 ; i < capacity ; i++)
            array[i] = NULL;

}


//this funch returns the index of the position in the table into which the
//word will be inserted to
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



//search function
bool HashTable::search(string aWord){
    if(search2(aWord) != -1){//if the word exists into the table just increase its appearances

        array[search2(aWord)]->appearances++;
        return true;
    }else{
        return false;
    }
}
//this function searchs through the hash table if the given word exists and if it exists it returns its 
//position in the table
int HashTable::search2(string aWord){
    int hashIndex = hashFunction(aWord);

    int counter  = 0;
    int i = 1;
     while(array[hashIndex] != NULL)
        {

            if(counter++ > capacity)
               return -1;
            if(array[hashIndex]->word == aWord){

               return hashIndex;
            }

            hashIndex = hashIndex + pow(i, 2);
            i++;
            hashIndex %= capacity;
        }

        //If not found return -1
        return -1;
}
//insert function
void HashTable::insert(string aWord){
     int hashIndex = hashFunction(aWord);
     if(!search(aWord)){//if not found inside the table then insert it
         Hash_Node *newHash_Node = new Hash_Node(aWord, 1);
         insert(newHash_Node, hashIndex);

      }
}
//this funch is used to insert the word into the hash table 
void HashTable::insert(Hash_Node* value, int hashIndex){
            int i = 1;
       while(array[hashIndex] != NULL){
             hashIndex = hashIndex + pow(i, 2);
             i++;
             hashIndex %= capacity;
           }

           if(array[hashIndex] == NULL){

                 array[hashIndex] = value;
                 size++;
           }
}
