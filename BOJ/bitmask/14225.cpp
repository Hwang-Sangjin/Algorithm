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

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
bool check[2000000];


int main() {
	int N,temp;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 1; i < (1 << N); i++) {
		vector<int> mask;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j))mask.push_back(1);
			else mask.push_back(0);
		}
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (mask[i] == 0) continue;
			temp += v[i];
		}
		check[temp] = true;
	}

	int res;
	for (int i = 1; i < 2000000; i++) {
		if (check[i] == false) {
			res = i;
			break;
		}
	}
	cout << res;

	return 0;
}