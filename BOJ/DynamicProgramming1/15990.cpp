#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[100002][4];
bool check[100002];

int main() {

	int t;
	cin >> t;
	int m = 4;

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;//2 1
	dp[3][2] = 1;//1 2
	dp[3][3] = 1;//3
	dp[4][1] = 2;// 1 2 1, 3 1
	dp[4][2] = 0;
	dp[4][3] = 1;//1 3
	for (int i = 1; i <= 4; i++) {
		check[i] = true;
	}

	while (t--) {
		int n;
		cin >> n;
		if (m >= n) {
			cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009<<'\n';
			continue;
		}

		for (int i = 5; i <= n; i++) {
			if (check[i])continue;
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%1000000009;
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
			check[i] = true;
		}

		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
	}
	
	return 0;
}