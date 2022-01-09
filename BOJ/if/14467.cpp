#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <map>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
map<int, int> m;

int main() {
	int N,num,location,res=0;
	cin >> N;

	while (N--) {
		cin >> num >> location;
		if (location == 0) location = -1;

		if (m[num] == 0) {
			m[num] = location;
		}
		else {
			if (m[num] * location == 1) {
				continue;
			}
			else {
				m[num] = location;
				res++;
			}
		}
	}
	cout << res;

	return 0;
}