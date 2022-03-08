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

int N;
int maze[1002];
bool v[1002];
int res = -1;

void bfs() {
	queue<pair<int,int>>q;
	q.push({ 0,0 });
	v[0] = true;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int ti = t.first;
		int tcnt = t.second;
		
		if (ti == N - 1) {
			res = tcnt;
			break;
		}

		for (int i = 1; i <= maze[ti]; i++) {
			if (v[ti + i] == true) continue;
			q.push({ ti + i,tcnt + 1 });
			v[ti + i] = true;
		}
	}
}

int main() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		maze[i] = temp;
	}

	bfs();
	cout << res;
}