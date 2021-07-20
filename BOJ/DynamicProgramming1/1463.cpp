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

int dp[1000002];

int main() {

	int x;
	cin >> x;
	memset(dp, -1, sizeof(dp));

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= x; i++) {
		
		if (i % 3 == 0) {
			dp[i] = dp[i / 3] + 1;
		}
		if (i % 2 == 0) {
			if (dp[i] == -1) {
				dp[i] = dp[i / 2] + 1;
			}
			else {
				dp[i] = min(dp[i / 2], dp[i / 3]) + 1;
			}
		}
		if (dp[i] == -1) {
			dp[i] = dp[i-1] + 1;
		}
		else {
			dp[i] = min(dp[i], dp[i -1] + 1);
		}
	}
	cout << dp[x];
	return 0;
}