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

int le[1002];
int ri[1002];
int dp[1002];

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j < i; j++) {
			if (v[i] > v[j] && le[i] < le[j] + 1) {
				le[i] = le[j] + 1;
			}
			
		}
	}

	for (int i = n; i >= 1; i--) {
		
		for (int j = i+1; j <=n; j++) {
			if (v[i] > v[j] && ri[i] < ri[j] + 1) {
				ri[i] = ri[j] + 1;
			}
		}
		//cout << ri[i] << ' ';
	}

	for (int i = 1; i <= n; i++) {
		res = max(res, le[i] + ri[i] + 1);
	}

	cout << res;
	
	return 0;
}