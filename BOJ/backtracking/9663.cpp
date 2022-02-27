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

using namespace std;

bool Col[16];
bool Diag[35];
bool antiDiag[35];

int N;
int cnt = 0;

void go(int index) {
	if (index == N+1) {
		cnt++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		int d = (i - index) + (N - 1);
		int ad = (i + index) - 2;
		if (Col[i] || Diag[d] || antiDiag[ad]) continue;
		Col[i] = true;
		Diag[d] = true;
		antiDiag[ad] = true;
		go(index + 1);
		Col[i] = false;
		Diag[d] = false;
		antiDiag[ad] = false;
	}
}

int main() {
	cin >> N;

	go(1);

	cout << cnt;
}