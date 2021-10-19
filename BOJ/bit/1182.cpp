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
	int N, S,temp;
	cin >> N >> S;
	int res = 0;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	//if (1 & 3) cout << "!!!";

	for (int i = 1; i < (1 << N); i++) {

		int temp = 0;
		for (int j = 0; j < N; j++) {
			//cout << i << ' ' << (1 << j) << '\n';
			if (i & (1 << j)) {
				temp += v[j];
			}
		}
		if (temp == S) res++;
	}
	cout << res;

	return 0;
}