#ifndef ASS2_2_FILTER_2_H
#define ASS2_2_FILTER_2_H

#include "ReadFilteredWords.h"

class Filter_2 : public ReadFilteredWords{
public:
    // constructor
    Filter_2(const char *fname): ReadFilteredWords(fname)
    {
    }
    // this method is the filter to detect the consistence of arg: word
    // return true if the filter accept the word
    virtual bool filter(string word);

};
#endif //ASS2_2_FILTER_2_H
