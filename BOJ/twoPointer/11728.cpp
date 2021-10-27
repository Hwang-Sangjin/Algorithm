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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M,temp;
	cin >> N >> M;
	vector<int> A;
	vector<int> B;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	vector<int>res;

	int a = 0, b = 0;
	while (a != N  && b != M) {
		if (A[a] <= B[b]) {
			res.push_back(A[a]);
			a++;
		}
		else {
			res.push_back(B[b]);
			b++;
		}
	}

	if (a < N) {
		while (a != N) {
			res.push_back(A[a++]);
		}
	}
	else {
		while (b != M) {
			res.push_back(B[b++]);
		}
	}

	for (auto t : res)cout << t << ' ';

	return 0;
}