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

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

const int INF = 1000000000;

using namespace std;
int N;
vector<int> v;
vector<int> oper;
long long minRes = INF;
long long maxRes = -INF;


void go(int level, int plus, int minus, int multiple, int divide, long long res) {
	//cout << level << ' ' << plus << ' ' << minus << ' ' << multiple << ' ' << divide << ' ' << res << '\n';
	if (level == N) {
		if (maxRes < res)maxRes = res;
		if (minRes > res)minRes = res;
		return;
	}

	if (oper[0] > plus) go(level + 1, plus + 1, minus, multiple, divide, res + v[level]);
	if (oper[1] > minus) go(level + 1, plus, minus + 1, multiple, divide, res - v[level]);
	if(oper[2]>multiple) go(level + 1, plus, minus, multiple+1, divide, res * v[level]);
	if (oper[3] > divide) {
		long long t;
		if (res < 0) {
			t = abs(res) / v[level];
			t = -t;
		}
		else {
			t = res / v[level];
		}
		go(level + 1, plus, minus, multiple, divide + 1, t);
	}
}

int main() {
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		cin >> temp;
		oper.push_back(temp);
	}
	
	go(1, 0, 0, 0, 0, v[0]);

	cout << maxRes << '\n' << minRes;
	return 0;
}