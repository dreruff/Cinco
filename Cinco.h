/*
  Greg Ruffin gruffin gregoryaruffin@gmail.com
  Cinco.h
  11/6/14
  Cinco game
*/

#ifndef CINCO_H
#define CINCO_H

#include <iostream>
#include <locale>
#include "Dictionary.h" 

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Cinco{
 public:
  Cinco(){ cheated=false; numguesses=0; dict = new Dictionary("cinco-words.txt");}
  void start(){ ConsoleUI(); } // public interface to play game of cinco
 private:
  void ConsoleUI();  // play the game with text/keybd/screen UI  
  void getGuess();    
  void gameOver();
  int countMatchingLetters(string, string); // find common letters in any order
  int countInPlaceLetters(string, string);  // find common letters in place
  void tolower(string &);
  Dictionary *dict; // legal words for the game
  int numguesses; // track number of guesses used
  bool cheated; // flag set to true if cheat code is used
  string secret; // word to guess
};

#endif
