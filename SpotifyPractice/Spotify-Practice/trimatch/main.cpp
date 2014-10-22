//
//  main.cpp
//  trimatch
//
//  Created by Haoquan Guo on 3/9/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, const char * argv[])
{
    int n;
    vector<int> data;

    cin >> n;
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        data.push_back(k);
    }

    for (int i = 0; i < n - 1; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (data[i] > data[j]) {
                data[i] = data[i] xor data[j];
                data[j] = data[i] xor data[j];
                data[i] = data[i] xor data[j];                
            }
        }
    }
    
    for (int i = 1; i < n - 1; i ++) {
        int ptr1 = i-1;
        int ptr2 = i+1;
        while (ptr1 >= 0 || ptr2 < n) {
            int diff = data[ptr1] + data[i] > data[ptr2];
            if (diff == 0) {
                
            }
        }
    }
    
    return 0;
}

