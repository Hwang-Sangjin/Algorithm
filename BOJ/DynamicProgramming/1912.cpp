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
long long dp[100002];

int main() {
	int n;
	cin >> n;
	long long res = -1002;

	vector < long long > v(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	dp[1] = v[1];
	if (res < dp[1]) res = dp[1];

	for (int i = 2; i <= n; i ++ ) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		res = max(res, dp[i]);
	}

	cout << res;
	
	return 0;
}