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
         t.insertion(word);
       
          
      }
    }else{
        cerr << "Coud not open the file" << endl;
    }

       t.inOrder();
      t.deleletion("by");
      cout << "after deletion" << endl;
      t.inOrder();
    

    return 0;
}
