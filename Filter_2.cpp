#include "Filter_2.h"
// this filter accept at least 1 letter and at least 1 number
bool Filter_2::filter(string word){
    bool accept_letter = false; // whether a word contain at least one letter
    bool accept_number = false; // whether a word contain at least one number
    for (char i : word) { // traverse every character in a word
        // if at least 1 letter ( UPPER OR LOWER CASE)
        if((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')){
            accept_letter = true;
        }
            // if at least 1 number
        else if(i >= '0' && i <= '9'){
            accept_number = true;
        }
    }
    return accept_letter && accept_number; // return true only when both are accepted.
}
