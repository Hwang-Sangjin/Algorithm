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
int N, M;
int map[22][22];
int res;
bool v[22][22][22][22];
int fi, fj, si, sj;

bool bfs() {
	queue <pair<pair<pair<int, int>, pair<int, int>>,int>> q;
	q.push({ { {fi,fj},{si,sj}},0 });
	v[fi][fj][si][sj] = true;
	bool available = false;

	while (!q.empty()) {
		auto tt = q.front();
		q.pop();
		auto t = tt.first;
		auto cnt = tt.second;
		auto f = t.first;
		auto s = t.second;
		int tfi = f.first;
		int tfj = f.second;
		int tsi = s.first;
		int tsj = s.second;

		int coinCnt = 2;
		if (tfi == 0 || tfj == 0 || tfi >= N + 1 || tfj >= M + 1) coinCnt--;
		if (tsi == 0 || tsj == 0 || tsi >= N + 1 || tsj >= M + 1) coinCnt--;

		if (coinCnt == 0) continue;
		if (coinCnt == 1) {
			res = cnt;
			if (res <= 10) {
				available = true;
			}
			break;
		}

		for (int k = 0; k < 4; k++) {
			int nfi = tfi + di[k];
			int nfj = tfj + dj[k];
			int nsi = tsi + di[k];
			int nsj = tsj + dj[k];

			if (map[nfi][nfj] != 0) {
				nfi = tfi;
				nfj = tfj;
			}
			if (map[nsi][nsj] != 0) {
				nsi = tsi;
				nsj = tsj;
			}

			if (v[nfi][nfj][nsi][nsj] == true || (nfi == nsi && nfj == nsj)) continue;

			q.push({ {{nfi,nfj},{nsi,nsj}},cnt + 1 });
			v[nfi][nfj][nsi][nsj] = true;
		}
	}

	return available;
}

int main() {
	cin >> N >> M;
	char temp;
	int coinCnt = 0;
	
	for (int i = 1; i <= N; i++) {
		scanf_s("%1c", &temp);
		for (int j = 1; j <= M; j++) {
			scanf_s("%1c", &temp);
			//cout << temp << ' ';
			if (temp == 'o') {
				if (coinCnt == 0) {
					fi = i;
					fj = j;
					coinCnt++;
				}
				else if (coinCnt == 1) {
					si = i;
					sj = j;
					coinCnt++;
				}
				map[i][j] = 0;
			}
			else if (temp == '.') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}

	/*for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}*/

	if (bfs()) {
		cout << res;
	}
	else cout << -1;
	
	return 0;
}