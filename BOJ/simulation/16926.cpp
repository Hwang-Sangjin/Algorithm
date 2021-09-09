//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int map[302][302];
int N, M, R;

int main() {
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int minCL = min(N, M);
	int totalLevel = minCL / 2 + 0.5;
	//cout << totalLevel<<'\n';

	for (int level = 0; level < totalLevel; level++) {
		int cnt = ((N - (level * 2)) + (M - (level * 2))) * 2 - 4;
		//cout << cnt << '\n';
		int r = R % cnt;

		//level, level    level,M-1-level 가로 ->
		//level+1, M-1-level    N-1-level, M-1-level 세로아래
		//N-1-level,M-1-level-1    N-1-level,level 가로 <-
		//N-1-level-1,level    level+1,level 세로위

		queue<int> q;
		for (int j = level; j <= M - 1 - level; j++) {
			q.push(map[level][j]);
		}
		for (int i = level + 1; i <= N - 1 - level; i++) {
			q.push(map[i][M - 1 - level]);
		}
		for (int j = M - 1 - level - 1; j >= level; j--) {
			q.push(map[N-1-level][j]);
		}
		for (int i = N - 1 - level - 1; i >= level + 1; i--) {
			q.push(map[i][level]);
		}

		while (r--) {
			auto t = q.front();
			q.pop();
			q.push(t);
		}

		for (int j = level; j <= M - 1 - level; j++) {
			int t = q.front();
			q.pop();
			map[level][j] = t;
		}
		for (int i = level + 1; i <= N - 1 - level; i++) {
			int t = q.front();
			q.pop();
			map[i][M - 1 - level] = t;
		}
		for (int j = M - 1 - level - 1; j >= level; j--) {
			int t = q.front();
			q.pop();
			map[N - 1 - level][j]=t;
		}
		for (int i = N - 1 - level - 1; i >= level + 1; i--) {
			int t = q.front();
			q.pop();
			map[i][level] =t;
		}
		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}