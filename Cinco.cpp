/*
  Greg Ruffin gruffin gregoryaruffin@gmail.com
  Cinco.cpp
  Assignment 4 Cinco!
  11/6/14
  Cinco game
  code status: working/tested
*/

#include "Cinco.h"

// play the game with text/keybd/screen UI
void Cinco::ConsoleUI(){
  cout << "CS19: Cinco!" << endl << "by Greg Ruffin" << endl;
  cout << "I'm thinking of a five letter word..." << endl;
  secret = dict->getLegalSecretWord();
  getGuess();
  gameOver();
}

void Cinco::getGuess(){
  string guess;  
  do{
    cout << "Your guess? ";
    cin >> guess;
    tolower(guess);
    if(guess==secret) numguesses++;   
    else if(guess=="xxxxx"){                         //test for cheat code
      cout << "Secret Word is: " << secret << endl;      
      numguesses++; cheated = true;
    }
    else if(dict->validWord(guess)){
      cout << "Matching: " << countMatchingLetters(guess, secret) << endl;
      cout << "In-Place: " << countInPlaceLetters(guess, secret) << endl;
      numguesses++;
    }
    else{
      cout << "I don't know that word." << endl;  
    }
  }while(guess!=secret);
}

//Prints number of guesses and if user cheated.
void Cinco::gameOver(){
  if(cheated){
    cout << "Correct! You got it in " << numguesses << " guesses, but only by cheating." << endl;
  }else{
    if(numguesses==1) 
      cout << "Correct! You got it in 1 guess." << endl;
    cout << "Correct! You got it in " << numguesses << " guesses." << endl;
  }
}

//find common letters in any order
int Cinco::countMatchingLetters(string guess, string secret){
  int counter = 0;
  bool repeat[5] = {0};
  for(int i=0;i<guess.length();i++){
    for(int j=0;j<secret.length();j++){
      if(guess[i]==secret[j]&&!repeat[j]){
	counter++;
	repeat[j]=true;
      }}}
  return counter;
}

// find common letters in place
int Cinco::countInPlaceLetters(string guess, string secret){
  int counter = 0;
  for(int i=0;i<guess.length();i++)
    if(guess[i]==secret[i])
      counter++;
  return counter;
}

//converts characters of string to lowercase if not already.
void Cinco::tolower(string &guess){
  std::locale loc;
  for (int i=0;i<guess.length();i++)           
    guess[i] = std::tolower(guess[i],loc);
}
