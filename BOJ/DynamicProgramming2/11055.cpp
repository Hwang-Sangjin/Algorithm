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

int dp[1002];

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		dp[i] = v[i];
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (v[i] > v[j] && dp[i] < dp[j] + v[i]) {
				dp[i] = dp[j] + v[i];
			}
		}
		res = max(res, dp[i]);
	}

	cout << res;
	
	return 0;
}