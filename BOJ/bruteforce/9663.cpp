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
int N;
bool row[16];
bool dia[35];
bool antiDia[35];
int cnt = 0;

void go(int index) {
	//cout << index << '\n';
	if (index == N + 1) {
		cnt++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		int d = (i-index)+(N-1);
		int ad =(i+index)-2;
		if (row[i] || dia[d] || antiDia[ad]) continue;

		row[i] = true;
		dia[d] = true;
		antiDia[ad] = true;

		go(index + 1);

		row[i] = false;
		dia[d] = false;
		antiDia[ad] = false;
	}
}

int main() {
	cin >> N;

	go(1);
	cout << cnt;
	
	return 0;
}