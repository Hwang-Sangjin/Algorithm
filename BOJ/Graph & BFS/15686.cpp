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

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;

int map[52][52];
bool v[52][52];
int N, M;
int dis[100][13];
vector<pair<int, int>>chicken;
vector<pair<int, int>>house;

int distance(pair<int, int>a, pair<int, int>b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	cin >> N >> M;
	int res = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			dis[i][j] = distance(house[i], chicken[j]);
		}
	}

	vector<int> mask(M, 1);
	for (int i = 0; i < chicken.size() - M; i++) {
		mask.push_back(0);
	}
	sort(mask.begin(), mask.end());

	do {
		vector<int> aliveChickenIndex;
		for (int i = 0; i < mask.size(); i++) {
			if (mask[i] == 1) aliveChickenIndex.push_back(i);
		}

		int total = 0;
		for (int i = 0; i < house.size(); i++) {
			int temp = -1;

			for (auto t : aliveChickenIndex) {
				if (temp == -1) temp = dis[i][t];
				else {
					temp = min(temp, dis[i][t]);
				}
			}
			total += temp;
		}
		if (res == -1) res = total;
		else {
			res = min(res, total);
		}

	} while (next_permutation(mask.begin(), mask.end()));

	cout << res;
	return 0;
}