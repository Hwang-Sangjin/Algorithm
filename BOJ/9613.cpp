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

int gcd(int x, int y) {
	int z;

	while (y != 0) {
		z = x % y;
		x = y;
		y = z;
	}

	return x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;

		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}

		long long res = 0;
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				res += gcd(v[i], v[j]);
			}
		}
		cout << res << '\n';

	}

	

	return 0;
}