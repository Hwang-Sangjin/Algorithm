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

int main() {
	cin >> N >> M;

	vector<int> v;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	int s=0, e=0, sum = 0, cnt = 0;

	while (1) {
		if (sum < M) {
			if (e == v.size()) break;
			sum += v[e];
			e++;
		}
		else if (sum == M) {
			cnt++;
			if (e == v.size()) break;
			sum += v[e];
			e++;
		}
		else {
			sum -= v[s];
			s++;
		}
	}
	cout << cnt;

}