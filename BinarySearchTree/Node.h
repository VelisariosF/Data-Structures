#include <iostream> 
#include <string>
using namespace std; 
class Node{
    private:
      string word;
      int appearances;

    public:
      Node();
      Node(string aWord, int aprs);
      void setWord(string aWord);
      void setAppearances(int aprs);
      string getWord();
      int getAppearances();
      Node operator>(Node k);
      Node operator>=(Node k);
      Node operator<(Node k);
      Node operator<=(Node k);
      Node operator==(Node k);
};