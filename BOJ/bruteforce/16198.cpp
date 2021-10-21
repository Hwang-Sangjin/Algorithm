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

#define INF 987654321

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
int N;
vector<int> marble;
bool v[12];

int left(int x) {
	for (int i = 1; i <= x; i++) {
		int ni = x - i;
		if (v[ni] == true) continue;
		else {
			return ni;
		}
	}
}
int right(int x) {
	for (int i = 1; x+i < N; i++) {
		int ni = x + i;
		if (v[ni] == true) continue;
		else {
			return ni;
		}
	}
}

int main() {
	cin >> N;
	int temp;
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		marble.push_back(temp);
	}

	vector<int> mask;
	for (int i = 1; i < N - 1; i++) {
		mask.push_back(i);
	}

	do {
		memset(v, false, sizeof(v));
		int temp = 0;
		for (auto t : mask) {
			v[t] = true;
			int l = left(t);
			int r = right(t);
			//cout << l << ' ' << r << '\n';
			temp += marble[l] * marble[r];
		}

		res = max(res, temp);

	} while (next_permutation(mask.begin(), mask.end()));

	cout << res;
	return 0;
}