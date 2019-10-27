#include "Filter_1.h"
#include "Filter_2.h"
#include "Filter_3.h"
#include "ReadFilteredWords.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> PAIR;

// sort words by comparing their valve
class SortWords {
public:
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        return lhs.second > rhs.second;
    }
};

int main(){
    ReadFilteredWords *pFilteredWords;
    char filename[256];
    int choice; // user select the filter

    // ask user to input filename, and select the filter they want to apply with
    cout << "Please enter the filename: ";
    cin >> filename;
    cout << "Please select a filter (1, 2, 3): ";
    cin >> choice;
    // create corresponding objects by supplying filename
    if(choice == 1){
        pFilteredWords = new Filter_1(filename);
    }
    else if(choice == 2){
        pFilteredWords = new Filter_2(filename);
    }
    else if(choice == 3){
        pFilteredWords = new Filter_3(filename);
    }

    map<string, int> wordCount; // track the number of occurrences of each filtered word
    while(true){ //repeatedly get next filtered word until empty string occurred.
        string word = pFilteredWords->getNextFilteredWord();
        if(word.empty()){ // empty string
            break;
        }
        // if word could not be found until the end, means it occurs only once, add them to map
        if(wordCount.find(word) == wordCount.end()){
            wordCount[word] = 1;
        }
        else{
            wordCount[word] += 1; // count the occurrences of word
        }
    }

    // initialise the contents of a vector to be a copy of the contents of wordCount
    vector<PAIR> vWordCount(wordCount.begin(), wordCount.end());
    // sort the vector by occurrences
    sort(vWordCount.begin(), vWordCount.end(), SortWords());

    if(!vWordCount.empty()){
        cout << "The most frequent word is \"" << vWordCount[0].first << "\" which occurred " << vWordCount[0].second << " times." << endl;
        cout << "The least frequent word is \"" << vWordCount[vWordCount.size() - 1].first << "\" which occurred " << vWordCount[vWordCount.size() - 1].second << " times." << endl;
    }
    return 0;
}
