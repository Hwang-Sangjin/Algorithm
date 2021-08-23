#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;

int N, M;
int map[1002][1002];
queue<pair<int, int>> q;

bool bfs() {
	bool change = false;
	int n = q.size();

	while (n--) {
		auto t = q.front();
		q.pop();
		int ti = t.first;
		int tj = t.second;
		//cout << ti << ' ' << tj << '\n';

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];
			if (ni < 0 || nj < 0 || ni >= M || nj >= N || map[ni][nj] != 0) continue;
			q.push({ ni,nj });
			change = true;
			map[ni][nj] = 1;
		}

	}
	return change;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	
	int res = 0;
	while (1) {
		if (bfs() == false) {
			break;
		}
		res++;
		/*for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}*/
	}
	bool changeAll = true;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				changeAll = false;
				break;
			}
		}
		if (changeAll == false) break;
	}

	if (changeAll == false) {
		cout << -1;
	}
	else {
		cout << res;
	}

}

