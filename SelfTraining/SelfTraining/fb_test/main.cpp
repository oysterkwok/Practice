//
//  main.cpp
//  fb_test
//
//  Created by Haoquan Guo on 7/28/13.
//  Copyright 2013 NYU. All rights reserved.
//

#include <iostream>

using namespace std;

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int c, b, p;
		cin >> c >> b >> p;
		int k = p*c;
		if (k % 100 == 0) {
			k /= 100;
		}
		else {
			k = k / 100 + 1;
		}
		if (k < c - b) {
			k = c - b;
		}
		if (k >= c && p < 100) {
			int up = p*c*b-100*b*c+100*b;
			int down = 100*c-p*c;
			if (up % down == 0) {
				k = up / down + c - 1;
			}
			else {
				k = up / down + c;
			}
		}
		if (k < c - b) {
			k = c - b;
		}
		cout << k << '\n';
	}
    return 0;
}

