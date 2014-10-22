//
//  main.cpp
//  oct2_2011_b
//
//  Created by Haoquan Guo on 3/1/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k ++) {
        string seq;
        cin >> seq;
        int * pos = new int[40];
        for (int i = 0; i < 40; i ++) {
            pos[i] = 0;
        }
        int head = 0;
        char right = 'a', left = 'b', down = 'c';
        for (int i = 0; i < seq.length(); i ++) {
            cout << seq[i] << " ";
            if (seq[i] == right) {
                if (head > 0 && pos[head] % 5 == 0) {
                    left = left xor down;
                    down = left xor down;
                    left = left xor down;
                }
                pos[head] ++;
                if (head > 0 && pos[head] % 5 == 0) {
                    left = left xor down;
                    down = left xor down;
                    left = left xor down;
                }                
                right = right xor left;
                left = right xor left;
                right = right xor left;
                
                cout << head << " r " << left << right << down << pos[head] << "\n";
                continue;
            }
            if (seq[i] == left) {
                if (head > 0 && pos[head] % 5 == 0) {
                    right = right xor down;
                    down = right xor down;
                    right = right xor down;
                }
                pos[head] --;
                if (head > 0 && pos[head] % 5 == 0) {
                    right = right xor down;
                    down = right xor down;
                    right = right xor down;
                }
                right = right xor left;
                left = right xor left;
                right = right xor left;

                cout << head << " l " << left << right << down << pos[head] << "\n";
                continue;
            }
            if (seq[i] == down) {
                if (head > 0 && pos[head] % 5 == 0) {
                    pos[head-1] += pos[head] / 5;
                    pos[head] = 0;
                    head --;
                    cout << head << " u " << left << right << down << pos[head] << "\n";
                }
                else {
                    head ++;
                    cout << head << " d " << left << right << down << pos[head] << "\n";
                }
            }
        }
        
        if (head > 0 || pos[0] % 8 != 0) {
            cout << "open\n";
        }
        else {
            cout << "closed\n";
        }
    }
    return 0;
}

