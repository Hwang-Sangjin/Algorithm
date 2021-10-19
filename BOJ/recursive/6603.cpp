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
#include <stdio.h>

#define INF 987654321

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
int n;
vector<int> v;

void go(int cnt, int index, vector<int> t) {
	if (cnt == 6) {
		for (auto i : t) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = index + 1; i < n; i++) {
		vector<int> nextT = t;
		nextT.push_back(v[i]);
		go(cnt + 1, i, nextT);
	}
}

int main() {
	int temp;
	while (1) {
		cin >> n;
		if (n == 0) break;
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		
		for (int i = 0; i <= n - 6; i++) {
			vector<int> t;
			t.push_back(v[i]);
			go(1, i,t);
		}
		cout << '\n';
	}
	
	return 0;
}