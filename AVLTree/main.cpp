#include <iostream>
#include "AvlTree.h"
using namespace std;

int main(){
    AvlTree t;


    t.insertion("a");
    t.insertion("b");
    t.insertion("c");
   
    //t.deletion("a");
   // t.deletion("b");
    t.deletion("c");
    
    return 0;
}