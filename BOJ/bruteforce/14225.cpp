#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
bool visited[20000002];
vector<int> v;

int main() {
	int N;
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 1; i <= N; i++) {
		vector<int> mask(N - i, 0);
		for (int j = 0; j < i; j++) {
			mask.push_back(1);
		}

		do {
			int total = 0;

			for (int k = 0; k < N; k++) {
				if (mask[k] == 0) continue;
				total += v[k];
			}
			visited[total] = true;

		} while (next_permutation(mask.begin(), mask.end()));

		
	}
	int res = 0;
	for (int i = 1; i <= 2000000; i++) {
		if (visited[i] == false)
		{
			res = i;
			break;
		}
	}

	cout << res;
	return 0;
}