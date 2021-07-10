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

int main() {
	
	int n, s;
	int res = 0;
	cin >> n >> s;

	vector<int> v;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> mask(n,0);
	for (int i = 0; i < n; i++) {
		sort(mask.begin(), mask.end());
		mask[0] = 1;

		sort(mask.begin(), mask.end());

		do {
			int t = 0;
			for (int j = 0; j < n; j++) {
				if (mask[j] == 1) t += v[j];
			}

			if (t == s) {
				res++;
			}
			//cout << '\n';

		} while (next_permutation(mask.begin(), mask.end()));
	}
	cout<<res;
	
	return 0;
}