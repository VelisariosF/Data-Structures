#include <iostream>
#include <fstream>
#include "B.h"
using namespace std;


int main()
{
    B b, *root = NULL;
     ifstream f;
    string word;
/*    f.open("words->txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          b->insert(root, word);
      }
    }else{
        cerr << "Coud not open the file" << endl;
    }*/

    b.insertion("Vel");
    b.insertion("cat");
    b.insertion("dog");
    b.insertion("cat");
    b.insertion("dog");

    b.inorder();


    return 0;
}
