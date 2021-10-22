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
bool v[4000002];
int N;
vector<int> sosu;
int dp[4000002];

int main() {
	cin >> N;
	memset(v, true, sizeof(v));
	v[1] = false;
	for (int i = 2; i <= N; i++) {
		for (int j = 2; i * j <= N; j++) {
			v[i * j] = false;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (v[i]) {
			sosu.push_back(i);
			dp[i] = 1;
		}
	}

	int s = 0 , e = 0;
	int sum = 0;
	int cnt = 0;

	while (1) {
		if (sum == N) {
			cnt++;
			if (e == sosu.size()) break;
			sum += sosu[e];
			e++;
		}
		else if (sum < N) {
			if (e == sosu.size()) break;
			sum += sosu[e];
			e++;
		}
		else {
			sum -= sosu[s];
			s++;
		}

	}
	
	cout << cnt;
}