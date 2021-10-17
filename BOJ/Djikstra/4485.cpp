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

const int INF = 2500;
int N;
int map[125][125];
int Dist[125][125];

struct cmp {
	bool operator()(pair<int, pair<int, int>>a, pair<int, pair<int, int>> b) {
		return a.first > b.first;
	}
};

void bfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Dist[i][j] = INF;
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp>pq;
	pq.push({ map[0][0],{0,0} });
	Dist[0][0] = map[0][0];

	while (!pq.empty()) {
		auto t = pq.top();
		int tcost = t.first;
		auto tpos = t.second;
		int ti = tpos.first;
		int tj = tpos.second;
		pq.pop();
		//cout << tcost << ' ' << ti << ' ' << tj << '\n';

		if (Dist[ti][tj] < tcost) continue;

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];
			if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;

			if (Dist[ni][nj] > map[ni][nj] + tcost) {
				Dist[ni][nj] = map[ni][nj] + tcost;
				pq.push({ Dist[ni][nj] ,{ni,nj} });
			}
		}
	}
}

int main() {
	int level = 1;
	while (1) {
		cin >> N;
		if (N == 0)break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		bfs();

		cout << "Problem " << level << ": " << Dist[N - 1][N - 1]<<'\n';

		level++;
	}


	return 0;
}