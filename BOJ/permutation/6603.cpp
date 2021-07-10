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

	int n;

	while (cin >> n) {
		vector<int>v;
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		
		int m = n - 6;
		vector<int> mask(n,0);

		for (int i = 6; i < n; i++) {
			mask[i] = 1;
		}

		do {

			for (int i = 0; i < n; i++) {
				if (mask[i] == 0) {
					cout << v[i] << ' ';
				}
			}
			cout << '\n';

		} while (next_permutation(mask.begin(), mask.end()));

		cout << '\n';
	}

	return 0;
}