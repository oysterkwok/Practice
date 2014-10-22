//
//  main.cpp
//  sillysort
//
//  Created by Haoquan Guo on 2/21/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int main (int argc, const char * argv[])
{
    int n, t = 0;
    cin >> n;
    while (n > 0) {
        int score = 0;
        t ++;
        int * arr = new int[n];
        int * narr = new int[n];        
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
            narr[i] = arr[i];
        }
        for (int i = 0; i < n-1; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (narr[i] > narr[j]) {
                    narr[i] = narr[i] xor narr[j];
                    narr[j] = narr[i] xor narr[j];
                    narr[i] = narr[i] xor narr[j];
                }
            }
        }
        bool * used = new bool[n];
        for (int i = 0; i < n; i ++) {
            used[i] = false;
        }
        for (int i = 0; i < n; i ++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            vector<int> intset;
            intset.clear();
            intset.push_back(narr[i]);
            int j = i;
            while (arr[j] != narr[i]) {
                for (int k = 0; k < n; k ++) {
                    if (narr[k] == arr[j]) {
                        j = k;
                        used[k] = true;
                        intset.push_back(narr[k]);
                        break;
                    }
                }
            }
            if (intset.size() < 2) {
                continue;
            }
            else {
                int num1 = ((int)intset.size()-3) * intset[0];
                int num2 = ((int)intset.size()+1) * narr[0];
                if (num1 > num2) {
                    for (int j = 0; j < intset.size(); j ++) {
                        score += narr[0] + intset[j];
                    }
                    score += narr[0] + intset[0];
                }
                else {
                    for (int j = 1; j < intset.size(); j ++) {
                        score += intset[0] + intset[j];
                    }                    
                }
            }
        }
        cout << "Case " << t << ": " << score << "\n\n";
        cin >> n;
    }
    return 0;
}

