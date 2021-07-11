
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

bool check[5][5];
int map[5][5];
int n, m;

int res = 0;

void go(int index, int tempres) {

	int ti = index / m;
	int tj = index % m;



	if (index == n * m) {
		//cout << ti << ' ' << tj << ' ' << tempres << '\n';
		if (tempres > res) res = tempres;
		return;
	}



	if (check[ti][tj] == true) {
		go(index + 1, tempres);
		return;
	}

	else {
		int temp, ni, nj;
		temp = map[ti][tj];
		check[ti][tj] = true;
		go(index + 1, tempres + temp);
		check[ti][tj] = false;

		for (int k = 1; k + tj < m; k++) {
			ni = ti;
			nj = tj + k;
			if (check[ni][nj]) return;
			temp *= 10;
			temp += map[ni][nj];

			for (int j = 1; j <= k; j++) {
				check[ni][tj + j] = true;
			}
			go(index + 1, tempres + temp);
			for (int j = 1; j <= k; j++) {
				check[ni][tj + j] = false;
			}
		}
		temp = map[ti][tj];

		for (int k = 1; k + ti < n; k++) {
			ni = ti + k;
			nj = tj;
			temp *= 10;
			temp += map[ni][nj];
			for (int j = 1; j <= k; j++) {
				check[ti+j][nj] = true;
			}
			go(index + 1, tempres + temp);
			for (int j = 1; j <= k; j++) {
				check[ti + j][nj] = false;
			}
		}
	}

}


int main() {


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	string t;

	go(0, 0);


	cout << res;
	return 0;
}