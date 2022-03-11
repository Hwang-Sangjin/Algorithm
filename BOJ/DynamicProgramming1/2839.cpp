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
#include <set>
#include <map>

using namespace std;
int dp[5002];

int main() {
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		int a =5000, b = 5000;
		if (dp[i - 3] != -1) {
			a = dp[i - 3] + 1;
		}
		if (dp[i - 5] != -1) {
			b = dp[i - 5] + 1;
		}
		dp[i] = min(a, b);
		if (dp[i] == 5000) dp[i] = -1;
	}
	cout << dp[n];
}