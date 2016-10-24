/*
  Greg Ruffin gruffin gregoryaruffin@gmail.com
  Dictionary.h
  11/6/14
  Dictionary contains words for list of word for the game.
  code status: working/tested
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

using std::string;

class Dictionary{
 public:
  Dictionary(char *filename=""); // arg: filename of input words text file
  ~Dictionary();
  bool validWord(string word); // check if word is in Dictionary 
  string getLegalSecretWord(); // return a random word (w/out repeated letters)
 private:
  bool testSecretWord(int n); // test if word n has only unique letters
  void resize(int &);
  int numwords; // number of words in the dictionary
  string *words; //array of word in dictionary
};


#endif
