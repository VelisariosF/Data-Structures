#include "Node.h"

Node::Node(){
    word = "";
    appearances = 0;
}

Node::Node(string aWord, int aprs){
    word = aWord;
    appearances = aprs;
}

void Node::setWord(string aWord){
    word = aWord;
}

void Node::setAppearances(int aprs){
    appearances = aprs;
}

string Node::getWord(){
    return word;
}

int Node::getAppearances(){
    return appearances;
}

Node Node::operator<(Node k){
     Node temp = k;
        if(word < temp.getWord()){
          return temp;
        }
        return *this;
}

Node Node::operator<=(Node k){
     Node temp = k;
        if(word <= temp.getWord()){
          return temp;
        }
        return *this;
}

Node Node::operator>(Node k){
      Node temp = k;
        if(word > temp.getWord()){
          return *this;
        }
        return *this;
}

Node Node::operator>=(Node k){
      Node temp = k;
        if(word >= temp.getWord()){
          return *this;
        }
        return *this;
}

Node Node::operator==(Node k){
      Node temp = k;
        if(word == temp.getWord()){
          return *this;
        }
        return *this;
}


