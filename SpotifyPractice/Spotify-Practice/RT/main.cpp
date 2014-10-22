//
//  main.cpp
//  RT
//
//  Created by Haoquan Guo on 2/28/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main (int argc, const char * argv[])
{
    set<char> SentenceAnalyzer;
    set<char> WordAnalyzer;
    SentenceAnalyzer.insert('\n');
    SentenceAnalyzer.insert(',');
    SentenceAnalyzer.insert('.');
    WordAnalyzer.insert(' ');
    ifstream fin("/Users/oyster/Desktop/input.txt");
    string text, str;
    while (!getline(fin, str).eof()) {
        text.append(str + "\n");
    }
//    cout << text;
    string word, nonword;
    vector<int> WordInSent;
    vector<string> newtext;
    for (int i = 0; i < text.length(); i ++) {
        if (SentenceAnalyzer.find(text[i]) != SentenceAnalyzer.end()) {
            nonword.push_back(text[i]);
            if (word.length() > 0) {
                WordInSent.push_back((int)newtext.size());
                newtext.push_back(word);
                word.clear();
            }
            for (int j = 0; j < WordInSent.size() / 2; j ++) {
                string temp = newtext[WordInSent[j]];
                newtext[WordInSent[j]] = newtext[WordInSent[WordInSent.size()-j-1]];
                newtext[WordInSent[WordInSent.size()-j-1]] = temp;
            }
            WordInSent.clear();
            continue;
        }
        
        if (WordAnalyzer.find(text[i]) != WordAnalyzer.end()) {
            nonword.push_back(text[i]);
            if (word.length() > 0) {
                WordInSent.push_back((int)newtext.size());
                newtext.push_back(word);
                word.clear();
            }
            continue;
        }
        
        word.push_back(text[i]);
        if (nonword.length() > 0) {
            newtext.push_back(nonword);
            nonword.clear();
        }
    }
    if (word.length() > 0) {
        newtext.push_back(word);
        word.clear();
    }
    if (nonword.length() > 0) {
        newtext.push_back(nonword);
        nonword.clear();
    }
    for (int i = 0; i < newtext.size(); i ++) {
//        cout << "[" << i << "]";
        cout << newtext[i];
    }
    return 0;
}

