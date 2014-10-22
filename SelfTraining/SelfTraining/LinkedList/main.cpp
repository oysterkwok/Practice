//
//  main.cpp
//  LinkedList
//
//  Created by Haoquan Guo on 1/9/13.
//  Copyright 2013 NYU. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

list<int> calc_sum(list<int> x, list<int> y) {
	list<int> z;
	list<int> w;
	
	int xl = 0;
	int yl = 0;
	list<int>::iterator xi = x.begin();
	list<int>::iterator yi = y.begin();
	
	while (xi != x.end()) {
		xi ++;
		xl ++;
	}
	while (yi != y.end()) {
		yi ++;
		yl ++;
	}
	
	int wl = max(xl, yl);
	int xj = wl - xl;
	int yj = wl - yl;
	xi = x.begin();
	yi = y.begin();
	for (int wi = 0; wi < wl; wi ++) {
		int xk = 0;
		int yk = 0;
		if (xj > 0) {
			xj --;
		}
		else {
			xk = *xi;
			xi ++;
		}
		if (yj > 0) {
			yj --;
		}
		else {
			yk = *yi;
			yi ++;
		}
		w.push_back(xk+yk);
	}
	
	int nc = 0;
	int last = 0;
	list<int>::iterator wwi = w.begin();
	for (int wi = 0; wi < wl; wi ++) {
		int put = last + *wwi / 10;
		
	}
	return z;
}

int main (int argc, const char * argv[]) {

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

