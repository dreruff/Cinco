/*
  Greg Ruffin gruffin gregoryaruffin@gmail.com
  Dictionary.cpp
  11/6/14
  Dictionary of words used for the game.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Dictionary.h"

// arg: filename of input words text file
Dictionary::Dictionary(char *filename){
  std::ifstream in;
  int capacity = 1000; numwords = 0;
  words = new string[capacity];
  
  in.open(filename);
  if(in.fail()){
    std::cerr << "Error opening file." << std::endl;    
    exit(1);
  }
  
  while(getline(in, words[numwords])){
    if(numwords>=(capacity-1)){
      resize(capacity);
    }
    numwords++;
  }
  in.close();  
}

Dictionary::~Dictionary(){
  delete [] words; words = 0;
}


// check if word is in Dictionary 
bool Dictionary::validWord(string guess){
  if(guess.empty()) return false;
  if(guess.length()!=5) return false;
  int lo=0, hi=numwords, mid;
  while( lo <= hi){
    mid = (lo+hi)/2;
    if (words[mid] == guess)
      return true;
    if (words[mid] > guess){
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return false;
}

// return a random word (w/out repeated letters)
std::string Dictionary::getLegalSecretWord(){  
  int index = rand()%numwords+1;
  while(!testSecretWord(index)){
    index = rand()%numwords+1;
  }
  return words[index];
}

// test if word n has only unique letters
bool Dictionary::testSecretWord(int n){
  string temp = words[n];
  for(int i=0;i<temp.length();i++){
    for(int j=i+1;j<temp.length();j++){
      if(temp.at(i)==temp.at(j)) return false;
    }}
  return true;
}

//Resizes array words
void Dictionary::resize(int &capacity){
  capacity = capacity *2 +1;
  string *temp = new string[capacity];
  
  for(int i=0;i<numwords;i++){
    temp[i] = words[i];
  }
  
  delete [] words;
  words = temp;
}
