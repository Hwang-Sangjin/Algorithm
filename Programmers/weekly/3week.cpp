#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };
vector<pair<int, int>> filled[2500];
vector<pair<int, int>> filling[1000];
vector<vector<int>> board;
vector<vector<int>> Table;
bool v[52][52];
int n;

void bfs(int x, int y, int index) {
	queue <pair<int, int>> q;
	q.push({ x,y });
	v[x][y] = true;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int ti = t.first;
		int tj = t.second;
		filled[index].push_back({ ti,tj });

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= n || v[ni][nj] || board[ni][nj] == 1) continue;
			q.push({ ni,nj });
			v[ni][nj] = true;
		}
	}

}

void bfs2(int x, int y, int index) {
	queue <pair<int, int>> q;
	q.push({ x,y });
	v[x][y] = true;

	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int ti = t.first;
		int tj = t.second;
		filling[index].push_back({ ti,tj });

		for (int k = 0; k < 4; k++) {
			int ni = ti + di[k];
			int nj = tj + dj[k];
			if (ni < 0 || nj < 0 || ni >= n || nj >= n || v[ni][nj] || Table[ni][nj] == 0) continue;
			q.push({ ni,nj });
			v[ni][nj] = true;
		}
	}
}

void rotate() {
	int h = Table.size();
	vector<vector<int>> temp(h, vector<int>(h));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			temp[h - 1 - i][j] = Table[i][j];
		}
	}
	for (int i = 1; i < h; i++) {
		for (int j = 0; j < i; j++) {
			int tt = temp[i][j];
			temp[i][j] = temp[j][i];
			temp[j][i] = tt;
		}
	}
	Table = temp;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;
	board = game_board;
	Table = table;
	n = game_board.size();

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (game_board[i][j] == 0 && v[i][j] == false) {
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}

	int tcnt = 0;
	for (int rotateCnt = 0; rotateCnt < 4; rotateCnt++) {
		for (int i = 0; i < tcnt; i++) {
			filling[i].clear();
		}
		memset(v, false, sizeof(v));
		tcnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (Table[i][j] == 1 && v[i][j] == false) {
					bfs2(i, j, tcnt);
					tcnt++;
				}
			}
		}



		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << Table[i][j];
			}
			cout << '\n';
		}
		cout << '\n';

		//filling filled 비교
		//같은 구조면 Table에 있는거 0 board에 있는거 1로
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < tcnt; j++) {
				if (filled[i].size() != filling[j].size()) continue;

				int disx = filled[i][0].first - filling[j][0].first;
				int disy = filled[i][0].second - filling[j][0].second;

				bool check = true;

				for (int k = 0; k < filled[i].size(); k++) {
					if (filled[i][k].first != filling[j][k].first + disx || filled[i][k].second != filling[j][k].second + disy) {
						check = false;
						break;
					}
				}
				if (check == true) {
					for (int k = 0; k < filled[i].size(); k++) {
						cout << filled[i][k].first << ' ' << filled[i][k].second << '\n';
						board[filled[i][k].first][filled[i][k].second] = 1;
					}
					filled[i].clear();
					cout << '\n';
					for (int k = 0; k < filling[j].size(); k++) {
						cout << filling[j][k].first << ' ' << filling[j][k].second << '\n';
						Table[filling[j][k].first][filling[j][k].second] = 0;
					}


					answer += filling[j].size();
					cout << '\n' << answer << '\n';
					filling[j].clear();
				}
			}
		}
		if (rotateCnt != 3) {
			rotate();
		}
	}

	return answer;
}