#include <iostream>
using namespace std;

int dp[1002];

int main() {

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;


	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n];

	return 0;
}