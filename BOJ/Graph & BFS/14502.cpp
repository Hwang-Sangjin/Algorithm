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
int res = -1;
int N, M;
vector<vector<int>> map(10);
vector<pair<int, int>> virus;

void bfs() {
	vector<vector<int>> tempMap = map;
	bool v[10][10];
	memset(v, false, sizeof(v));
	queue<pair<int, int>> q;
	for (auto t : virus) {
		q.push(t);
		v[t.first][t.second] = true;
	}

	while (!q.empty()) {
		auto t= q.front();
		q.pop();
		int ti = t.first;
		int tj = t.second;
		//cout << ti << ' ' << tj << '\n';

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M || v[ni][nj] || tempMap[ni][nj] != 0) continue;
			q.push({ ni,nj });
			v[ni][nj] = true;
			tempMap[ni][nj] = 2;
		}
	}

	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempMap[i][j] == 0)temp++;
		}
	}

	if (res < temp) res = temp;
	return;
}

void go(int cnt, vector<pair<int,int>> wall, int index) {
	if (cnt == 3) {
		for (auto t : wall) {
			//cout << t.first << ' ' << t.second << '\n';
			map[t.first][t.second] = 1;
		}
		//cout << "\n\n";
		bfs();

		for (auto t : wall) {
			map[t.first][t.second] = 0;
		}
		return;
	}

	for (int i = index + 1; i < N*M; i++) {
		int ni = i / M;
		int nj = i % M;
		if (map[ni][nj] != 0) continue;
		wall.push_back({ ni,nj });
		go(cnt + 1, wall, i);
		wall.pop_back();
	}
}

int main() {
	int temp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			map[i].push_back(temp);
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	vector<pair<int, int>> wall;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) continue;
			wall.push_back({ i,j });
			go(1, wall,i*M +j);
			wall.pop_back();
		}
	}
	cout << res;

	return 0;
}