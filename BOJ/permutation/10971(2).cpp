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
#include <map>
#include <set>

using namespace std;

int N;

int W[12][12];

int main() {
	cin >> N;

	int res = 100000000;
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			W[i][j] = temp;
		}
	}

	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	do {

		int startP = v[0];
		int cur;
		int next;
		int tempCost = 0;
		bool avail = true;
		for (int i = 0; i < N-1; i++) {
			cur = v[i];
			next = v[i + 1];
			if (W[cur][next] == 0) {
				avail = false;
				break;
			}
			else {
				tempCost += W[cur][next];
			}
		}
		if (avail) {
			if (W[next][startP] != 0) {
				tempCost += W[next][startP];

				res = min(res, tempCost);
			}
		}
	} while (next_permutation(v.begin(), v.end()));


	cout << res;
	return 0;
}