#include "Filter_1.h"
// this filter accept at least 1 CAP letter and 0 non-CAP letter
bool Filter_1::filter(string word){
    bool accept = false; // whether a word could pass this filter
    for (char i : word) { // traverse every character of a word
        // if at least 1 CAP letter detected, accepted!
        if(i >= 'A' && i <= 'Z'){
            accept = true;
        }
            // if non-CAP letter detected, not accepted!
        else if(i >= 'a' && i <= 'z'){
            accept = false;
            break; // if so, no need to loop further
        }
    }
    return accept;
}
