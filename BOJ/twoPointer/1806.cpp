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
int N, M;
int res = INF;

int main() {
	cin >> N >> M;

	vector<int> v;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	int s=0, e=0, sum = 0, cnt = 0;
	int res = 100000;
	while (1) {
		if (sum < M) {
			if (e == v.size()) break;
			sum += v[e];
			e++;
		}
		else if (sum == M) {
			
			if (res > e - s) res = e - s;
			if (e == v.size()) break;
			sum += v[e];
			e++;
		}
		else {
			if (res > e - s) res = e - s;
			sum -= v[s];
			s++;
		}
	}
	if (res == 100000)res = 0;
	cout << res;

}