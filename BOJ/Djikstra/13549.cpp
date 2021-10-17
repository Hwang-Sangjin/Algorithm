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


const int INF = 100001;
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;

int S, E;
bool v[100002];

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};

int djikstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
	pq.push({ 0,S });
	v[S] = true;

	while (!pq.empty()) {
		auto t = pq.top();
		int tindex = t.second;
		int tcost = t.first;
		//cout << tindex << ' ' << tcost << '\n';
		pq.pop();

		if (tindex == E) {
			return tcost;
		}

		if (tindex * 2 < INF && v[tindex * 2] == false) {
			
			v[tindex * 2] = true;
			pq.push({ tcost,tindex * 2 });
		}

		if (tindex +1 < INF && v[tindex +1] == false) {
			
			v[tindex + 1] = true;
			pq.push({tcost + 1, tindex + 1});
		}
		if (tindex - 1 >=0 && v[tindex - 1] == false) {
			
			v[tindex - 1] = true;
			pq.push({tcost + 1, tindex - 1});
		}
	}
}

int main() {
	cin >> S >> E;

	cout<<djikstra();

	return 0;
}