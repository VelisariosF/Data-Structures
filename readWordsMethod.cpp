#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream f;
    string word;
    f.open("words.txt", ios::in);
    char x;
    word.clear();
    if(f.is_open()){
      while(f >> word){
          cout << word << endl;
      }
    }else{
        cerr << "Coud not open the file" << endl;
    }
    return 0;
}