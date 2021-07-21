#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <time.h>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };
using namespace std;

int dp[10002];

int main() {
	int n;
	cin >> n;

	vector<int> wine(n+1);
	wine[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1],dp[i-2] + wine[i]);
		dp[i] = max(dp[i], dp[i - 3] + wine[i] + wine[i - 1]);
	}
	cout << dp[n];

	return 0;
}