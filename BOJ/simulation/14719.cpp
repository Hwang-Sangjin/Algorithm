#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;
vector<int> v;

int main()
{
	int res = 0;
	int H, W;
	cin >> H >> W;

	int temp;
	for (int i = 0; i < W; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 1; i < W-1; i++) {
		int left = 0;
		int right = 0;

		for (int j = i-1; j >= 0; j--) {
			if (left < v[j]) left = v[j];
		}
		for (int j = i + 1; j < W; j++) {
			if (right < v[j]) right = v[j];
		}

		int low = left > right ? right : left;

		if (low > v[i]) {
			res += low - v[i];
		}
		
	}

	cout << res;
}

