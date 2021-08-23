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

int N;
int map[27][27];
bool v[27][27];
vector<int> res;

void bfs(int x, int y) {
	queue <pair<int, int>> q;
	q.push({ x,y });
	map[x][y] = 0;
	v[x][y] = true;
	int cnt = 0;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int ti = t.first;
		int tj = t.second;
		//cout << ti << ' ' << tj << '\n';

		cnt++;

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N || v[ni][nj] || map[ni][nj] == 0 || map[ni][nj] >1) continue;
			q.push({ ni,nj });
			map[ni][nj] = 0;
			v[ni][nj] = true;
		}
	}
	res.push_back(cnt);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < N; j++) {
			map[i][j] = temp[j]-48;
		}
	}

	int cnt = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == true && map[i][j] == 0) {
				continue;
			}
			else if (map[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	sort(res.begin(), res.end());
	cout << cnt << '\n';
	for (auto t : res) {
		cout << t << '\n';
	}
}

