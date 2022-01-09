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
	int N, M;
	cin >> N >> M;

	map<string, int> m;
	string temp;
	while (N--) {
		cin >> temp;
		m[temp]++;
	}

	int cnt=0;
	vector<string>res;
	while (M--) {
		cin >> temp;
		if (m[temp] > 0) {
			cnt++;
			res.push_back(temp);
		}
	}
	sort(res.begin(), res.end());

	cout << cnt << '\n';
	for (auto t : res)cout << t << '\n';

	return 0;
}