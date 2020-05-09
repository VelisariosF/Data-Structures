#include <iostream>
#include <fstream>
#include "AvlTree.h"
using namespace std;

int main(){
    AvlTree t;
      ifstream f;
    string word;
    f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
         t.insertion(word);
       
        
      }
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }

       t.preOrder();

    f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
         t.insertion(word);
       
        
      }
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }
   
    f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
        if(t.search(word))
          t.deletion(word);
          cout<<"delete" << endl;
        
      }
      f.close();
    }else{
        cerr << "Coud not open the file" << endl;
    }

    if(t.search("The")){
      cout << "found" << endl;
    }else{
      cout << "Not" << endl;
    }


      
     
    

    return 0;
}
