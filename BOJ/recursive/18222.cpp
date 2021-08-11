#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;
long long p[61];

bool go(long long k) {
	if (k == 1) return false;
	else if (k == 2) return true;
	//cout << k << ' ';

	int index = 0;
	for (int i = 1; i <= 60; i++) {
		if (p[i] >= k) {
			index = i - 1;
			break;
		}
	}
	long long tt = p[index];
	long long t = k % tt;
	if (t == 0) t = tt;

	return !go(t);
}

int main()
{
	long long k;
	cin >> k;

	for (int i = 1; i <= 60; i++) {
		p[i] = pow(2, i);
	}

	cout << go(k);
}
