//
//  main.cpp
//  register
//
//  Created by Haoquan Guo on 2/15/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{
    int * queue = new int[8];
    int * prime = new int[8];
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;
    prime[5] = 13;
    prime[6] = 17;
    prime[7] = 19;
    
    for (int i = 0; i < 8; i ++) {
        cin >> queue[i];
    }
    int sum = 0;
    int k = 1;
    for (int i = 0; i < 8; i ++) {
        sum += queue[i] * k;
        k *= prime[i];
    }
    cout << 9699689 - sum << "\n";
    return 0;
}

