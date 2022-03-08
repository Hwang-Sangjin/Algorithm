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
#include <set>

using namespace std;
int N;
vector<int>v;
int operatorCnt[4];
long long resMin = 1000000001;
long long resMax = -1000000001;

void go(int index, long long total, int add, int sub, int mul, int div) {
	if (index == N) {
		resMin = min(resMin, total);
		resMax = max(resMax, total);
		return;
	}

	if (add != 0) {
		
		go(index + 1, total + v[index], add - 1, sub, mul, div);
	}
	if (sub != 0) {
		go(index + 1, total - v[index], add, sub-1, mul, div);
	}
	if (mul != 0) {
		go(index + 1, total * v[index], add, sub, mul-1, div);
	}
	if (div != 0) {
		long long t;
		if (total < 0) {
			t = abs(total) / v[index];
			t = -t;
		}
		else {
			t = total / v[index];
		}
		go(index + 1, t, add, sub, mul, div -1);
	}
}

int main() {
	cin >> N;
	int temp;
	int add, sub, mul, div;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cin >> add >> sub >> mul >> div;

	go(1, v[0], add, sub, mul, div);
	cout << resMax << '\n' << resMin;
}