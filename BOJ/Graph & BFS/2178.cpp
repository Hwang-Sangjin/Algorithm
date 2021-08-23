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
bool map[102][102];

int bfs(int x, int y) {
	queue <pair<pair<int, int>,int>> q;
	q.push({ {x,y},1 });
	map[x][y] = false;
	int res=0;

	

	while (!q.empty()) {
		auto t = q.front();
		q.pop();

		auto tpos = t.first;
		int tcnt = t.second;
		int ti = tpos.first;
		int tj = tpos.second;
		//cout << ti << ' ' << tj << '\n';

		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}*/

		if (ti == N && tj == M) {
			res = tcnt;
			break;
		}

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];
			if (ni <= 0 || nj <= 0 || ni > N || nj > M || map[ni][nj] == false) continue;
			q.push({ {ni,nj},tcnt + 1 });
			map[ni][nj] = false;
		}
	}
	return res;
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		//cout << temp<<'\n';
		for (int j = 0; j < M; j++) {
			if (temp[j] == '0') {
				map[i][j+1] = false;
			}
			else {
				map[i][j+1] = true;
			}
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}*/

	cout<< bfs(1, 1);
}

