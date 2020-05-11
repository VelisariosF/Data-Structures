#include <iostream> 
using namespace std;
int main(){
    int myVar,
      *myPointer;

  myVar = 8;
  myPointer = &myVar;

  cout << "delete-ing pointers " << endl;
  cout << "Memory address: " << myPointer << endl;

  // Seems I can't *just* delete it, as it triggers an error 
  delete myPointer;
  cout << "myPointer: " << myPointer << endl;
  // Error: a.out(14399) malloc: *** error for object 0x7fff61e537f4:
  // pointer being freed was not allocated
  // *** set a breakpoint in malloc_error_break to debug
  // Abort trap: 6

  // Using the new keyword befor deleting it works, but
  // does it really frees up the space? 
  myPointer = new int;
  delete myPointer;
  cout << "myPointer: " << myPointer << endl;
  // myPointer continues to store a memory address.

  // Using NULL before deleting it, seems to work. 
  myPointer = NULL;
  delete myPointer;
  cout << "myPointer: " << myPointer << endl;
  // myPointer returns 0.
}