#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;

bool v[102][102];
int dir[4] = { 1,0,3,2 };

int main() {

	int n;
	cin >> n;

	while (n--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		v[y][x] = true;
		d = dir[d];
		deque<int> origin;
		deque<int> next;
		origin.push_back(d);
		next.push_back(d);
		while (g--) {
			next = origin;


			while (!origin.empty()) {
				int t = origin.back();
				origin.pop_back();

				t = (t + 3) % 4;
				next.push_back(t);
			}

			origin = next;
		}
		int nx = x;
		int ny = y;
		while (!next.empty()) {
			int t = next.front();
			nx = nx + dj[t];
			ny = ny + di[t];
			
			v[ny][nx] = true;

			next.pop_front();
		}
	}

	/*for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}*/

	int res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			bool check = true;
			if (!v[i][j])check = false;
			if (!v[i + 1][j])check = false;
			if (!v[i][j + 1])check = false;
			if (!v[i + 1][j + 1])check = false;

			if (check) res++;
		}
	}
	
	cout << res;
	return 0;
}