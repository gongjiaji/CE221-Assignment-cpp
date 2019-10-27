#include "Filter_3.h"
#include <cctype>

// this filter accept string that contains only 1 puncture

bool Filter_3::filter(string word){
    int count = 0; // count the amount of puncture
    // traverse every character of a word
    for (char i : word) {
        // if a character is a puncture, count it
        if(ispunct(i)){
            count++;
        }
    }
    return count == 1; // return true only when exactly 1 puncture detected.
}
