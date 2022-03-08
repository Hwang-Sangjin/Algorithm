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
#include <map>

using namespace std;
bool v[10002];

int dp(int t) {
	int r = t;
	int res = t;

	while (r) {
		res += r % 10;
		r = r / 10;
	}

	return res;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		int t = dp(i);
		v[t] = true;
	}

	for (int i = 1; i < 10000; i++) {
		if (v[i])continue;
		cout << i << '\n';
	}
}