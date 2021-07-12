#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1002];

int main() {

	int n;
	cin >> n;

	vector<int> v;
	int temp;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	dp[1] = v[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = v[i];
		for (int k = 1; k < i; k++) {
			dp[i] = min(dp[i], dp[i - k] + v[k]);
		}
	}
	cout << dp[n];
	return 0;
}