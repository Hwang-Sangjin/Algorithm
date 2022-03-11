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
pair<int,int> dp[42];

int main() {
	int T,n;
	cin >> T;
	dp[0] = {1,0};
	dp[1] = {0,1};

	for (int i = 2; i <= 40; i++) {
		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
	}

	while (T--) {
		cin >> n;
		cout << dp[n].first << ' ' << dp[n].second << '\n';
	}
}