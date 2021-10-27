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

using namespace std;
int N;
int INF = 2000000000;
int res = INF;

int main() {

	cin >> N;
	vector<int>v;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int s = 0;
	int e = v.size() - 1;
	int sum = 0;
	int resS, resE;

	while (s < e) {
		int temp = v[s] + v[e];

		if (res > abs(temp)) {
			resS = s;
			resE = e;
			res = abs(temp);

			if (res == 0) break;
		}

		if (temp < 0) {
			s++;
		}
		else {
			e--;
		}
	}
	cout << v[resS] << ' ' << v[resE];

	return 0;
}