//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <time.h>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };
using namespace std;

int map[1002][1002];
bool v[1002][1002][2];
int N, M;
int res = -1;

void bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push({ {1,1},1 });
	v[1][1][1] = true;
	bool check = false;

	while (!q.empty()) {
		auto t = q.front();
		auto tpos = t.first;
		int tcnt = t.second;
		int ti = tpos.first; int tj = tpos.second;
		q.pop();

		if (ti == N && tj == M) {
			if (res == -1 || res > tcnt) {
				res = tcnt;
			}
		}
		
		//cout << ti << ' ' << tj << ' ' << tcnt << ' ' << tbreakcnt << '\n';

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];

			if (ni <= 0 || nj <= 0 || ni > N || nj > M) continue;
			
			if (map[ni][nj] == 0) {
				if (v[ti][tj][1]) {
					if (v[ni][nj][1]) continue;
					else {
						q.push({ {ni,nj},tcnt + 1 });
						v[ni][nj][1] = true;
					}
				}
				else if(v[ti][tj][0]) {
					if (v[ni][nj][0] || v[ni][nj][1]) continue;
					else {
						q.push({ {ni,nj},tcnt + 1 });
						v[ni][nj][0] = true;
					}
				}
			}
			else {
				if (v[ti][tj][1]) {
					if (v[ni][nj][0]) continue;
					else {
						q.push({ {ni,nj},tcnt + 1 });
						v[ni][nj][0] = true;
					}
				}
				else continue;
			}
		}
		if (check) break;
	}
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}*/

	bfs();

	cout << res;
	
	return 0;
}