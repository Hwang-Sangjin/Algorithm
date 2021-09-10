#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <climits>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
vector<int> num;
int N;
int resMin = INT_MAX;
int resMax = INT_MIN;

void dfs(int index, int add, int sub, int mul, int div, int sum) {
	if (index == N - 1) {
		resMin = min(sum, resMin);
		resMax = max(sum, resMax);
		return;
	}

	if (add != 0) dfs(index + 1, add - 1, sub, mul, div, sum + num[index + 1]);
	if (sub != 0) dfs(index + 1, add, sub - 1, mul, div, sum - num[index + 1]);
	if (mul != 0) dfs(index + 1, add, sub, mul - 1, div, sum * num[index + 1]);
	if (div != 0) {
		if (sum < 0) {
			sum *= -1;
			sum /= num[index + 1];
			sum *= -1;
			dfs(index + 1, add, sub, mul, div - 1, sum);
		}
		else {
			dfs(index + 1, add, sub, mul, div -1, sum/ num[index + 1]);
		}
	}
}

int main() {
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}

	int add, sub, mul, div;

	cin >> add >> sub >> mul >> div;

	dfs(0, add, sub, mul, div, num[0]);

	cout << resMax << '\n' << resMin;
	
	return 0;
}