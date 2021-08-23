#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

int di[8] = { -2,-1,1,2,2,1,-1,-2 };
int dj[8] = { 1,2,2,1,-1,-2,-2,-1 };

using namespace std;

int N;
bool v[302][302];
int x, y;
int tx, ty;
vector<int>res;

void bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push({ {x,y},0 });
	v[x][y] = true;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		auto tpos = t.first;
		int tcnt = t.second;
		int ti = tpos.first;
		int tj = tpos.second;

		if (ti == tx && tj == ty) {
			res.push_back(tcnt);
			break;
		}

		for (int k = 0; k < 8; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];
			if (ni < 0 || nj < 0 || ni >= N || nj >= N || v[ni][nj] == true) continue;

			q.push({ {ni,nj},tcnt + 1 });
			v[ni][nj] = true;
		}
	}

}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		memset(v, false, sizeof(v));
		
		cin >> x >> y >> tx >> ty;

		bfs();
	}
	for (auto t : res) {
		cout << t << '\n';
	}
}

