#include <iostream>
#include <fstream>
#include "AVLTREE.h"
using namespace std;

int main(){
    AVLTREE t;
      ifstream f;
    string word;
    f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
         if(t.insertkey(word)){
           t.increaseAPPS(word);
           continue;
         }
          t.insertion(word);
          
      }
    }else{
        cerr << "Coud not open the file" << endl;
    }

       t.inOrder();

    

    return 0;
}
