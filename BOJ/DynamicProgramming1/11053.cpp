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

	vector<int> v;

	int temp;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;

		for (int j = 1; j <= i; j++) {
			if (v[i] > v[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	int res = 0;

	for (int i = 1; i <= n; i++) {
		if (res < dp[i]) res = dp[i];
	}
	cout << res;
	
	return 0;
}