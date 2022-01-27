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
#include <map>
#include <set>

using namespace std;

int main() {
	int N,S,temp,cnt=0;
	cin >> N >> S;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	

	for (int level = 1; level <= N; level++) {
		vector<int> mask;
		for (int i = 0; i < level; i++) {
			mask.push_back(1);
		}
		for (int i = 0; i < N - level; i++) {
			mask.push_back(0);
		}

		sort(mask.begin(), mask.end());

		do {
			int T = 0;
			for (int i = 0; i < N; i++) {
				if (mask[i] == 1) {
					T += v[i];
				}
			}
			if (T == S) {
				cnt++;
			}

		} while (next_permutation(mask.begin(), mask.end()));
	}
	cout << cnt;

	return 0;
}