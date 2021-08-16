#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

int N, K, S, X, Y;
int map[202][202];
bool v[202][202];
queue<pair<int, int>> q[1002];

void bfs(int index) {
	int n = q[index].size();

	while (n--) {
		auto t = q[index].front();
		int ti = t.first;
		int tj = t.second;
		v[ti][tj] = true;
		q[index].pop();

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];

			if (ni <= 0 || nj <= 0 || ni > N || nj > N || v[ni][nj] || map[ni][nj] != 0) continue;

			map[ni][nj] = index;
			q[index].push({ ni,nj });
			v[ni][nj] = true;
		}
	}
}

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				q[map[i][j]].push({ i,j });
			}
		}
	}
	cin >> S >> X >> Y;

	while (S--) {
		for (int i = 1; i <= K; i++) {
			bfs(i);
		}
	}
	cout << map[X][Y];
	
}
