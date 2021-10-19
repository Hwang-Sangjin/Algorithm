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
	int n,temp;
	while (1) {
		cin >> n;
		if (n == 0) break;

		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}

		vector<int> mask(6, 0);

		for (int i = 0; i < n - 6; i++) {
			mask.push_back(1);
		}

		do {

			for (int i = 0; i < n; i++) {
				if (mask[i] == 1) continue;
				cout << v[i] << ' ';
			}
			cout << '\n';

		} while (next_permutation(mask.begin(), mask.end()));
		cout << '\n';
	}

	return 0;
}