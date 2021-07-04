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

int map[12][12];
int check[12][12];
int n, m, k;
int res = -1000000;
vector<int>v;

void close(int x, int y ,bool t) {
	if (t) {
		check[x][y]++;
		for (int k = 0; k < 4; k++) {
			int ti = x + di[k];
			int tj = y + dj[k];

			if (ti < 0 || tj < 0 || ti >= n || tj >= m) continue;
			check[ti][tj]++;
		}
	}
	else {
		check[x][y]--;
		for (int k = 0; k < 4; k++) {
			int ti = x + di[k];
			int tj = y + dj[k];

			if (ti < 0 || tj < 0 || ti >= n || tj >= m) continue;
			check[ti][tj]--;
		}
	}
	
}

void go(int cnt) {

	if (cnt == k) {
		//cout << '\n';
		int temp = 0;
		for (auto t : v) {
			//cout << t << ',';
			temp += t;
		}
		//cout<<"    " << temp<<'\n';
		if (temp > res) res = temp;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j]>0) continue;

				close(i, j, true);
				v.push_back(map[i][j]);
				//cout << i << ' ' << j << ',';
				go(cnt + 1);
				v.pop_back();
				close(i, j, false);
			}
		}
	}
}

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			close(i, j, true);
			v.push_back(map[i][j]);
			//cout << i << ' ' << j << ',';
			go(1);
			v.pop_back();
			close(i, j, false);
		}
	}
	cout << res;
	
	return 0;
}