#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;


int main()
{
    BinarySearchTree b, *root = NULL;
   
    ifstream f;
    string word;
   /* f.open("words.txt", ios::in);
    if(f.is_open()){
      while(f >> word){
          b.insertion(word);
      }
    }else{
        cerr << "Coud not open the file" << endl;
    }
    */
   b.insertion("vel");
   b.insertion("dog");
   b.insertion("dog");
    b.insertion("vel");
   b.insertion("cat");
   b.insertion("rat");
   
   
   
   b.inorder();

   b.deletion("cat");
   cout << "after deletion" << endl;
   b.inorder();
    return 0;
}
