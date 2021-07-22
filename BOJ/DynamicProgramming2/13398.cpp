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

long long dp[100002][2];

int main() {
	int n;
	cin >> n;
	vector<long long> v(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	dp[1][0] = dp[1][1] = v[1];

	long long res = v[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(v[i],dp[i-1][0] +v[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v[i]);
		res = max(max(res, dp[i][0]), dp[i][1]);
	}
	
	cout << res;
	
	return 0;
}