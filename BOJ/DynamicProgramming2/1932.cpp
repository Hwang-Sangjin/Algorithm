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

int dp[502][5002];
int map[502][502];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> map[i][j];
		}
	}

	dp[1][1] = map[1][1];
	dp[2][1] = dp[1][1] + map[2][1];
	dp[2][2] = dp[1][1] + map[2][2];

	for (int i = 3; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + map[i][1];
		dp[i][i] = dp[i - 1][i - 1] + map[i][i];
		for (int j = 2; j <= i - 1; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dp[n][i]);
	}
	cout << res;

	return 0;
}