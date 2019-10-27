#include "ReadFilteredWords.h"

// todo: build a constructor of ReadFilteredWords, exit program while inputted filename could not be found.

// Returns a string, being the next word in the file that satisfies the filter
string ReadFilteredWords::getNextFilteredWord(){
    string word;
    bool accept = false; // whether the word could pass the filter
    // traverse the words, put each word in filter
    while(isNextWord()){
        word = getNextWord();
        if(filter(word)){
            accept = true;
            break; // if word pass the filter, out of loop, return it.
        }
    }
    // if the word could not pass the filter, set it empty
    if(!accept){
        word = "";
    }
    return word;
}
