#include "pch.h"
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

using namespace std;

const int INF = 20000000+1;
int N, M, X;
vector<pair<int, int>> Ver[1002];
int Dist[1002];
int Back[1002];

int djikstra(int index) {
	for (int i = 1; i <= N; i++)Dist[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({ 0,index });
	Dist[index] = 0;

	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		int tcost = t.first;
		int tindex = t.second;

		for (int i = 0; i < Ver[tindex].size(); i++) {
			auto n = Ver[tindex][i];
			int nindex = n.first;
			int ncost = n.second;

			if (Dist[nindex] > tcost + ncost) {
				Dist[nindex] = tcost + ncost;
				pq.push({ tcost + ncost , nindex });
			}
		}
	}
	return Dist[X] + Back[index];
}

void comeBack() {
	for (int i = 1; i <= N; i++)Back[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,X });
	Back[X] = 0;

	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		int tcost = t.first;
		int tindex = t.second;

		for (int i = 0; i < Ver[tindex].size(); i++) {
			auto n = Ver[tindex][i];
			int nindex = n.first;
			int ncost = n.second;

			if (Back[nindex] > tcost + ncost) {
				Back[nindex] = tcost + ncost;
				pq.push({ tcost + ncost , nindex });
			}
		}
	}
}

int main() {
	int res = -1;
	cin >> N >> M >> X;
	int s, e, w;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> w;
		Ver[s].push_back({ e,w });
	}
	comeBack();

	for (int i = 1; i <= N; i++) {
		int temp = djikstra(i);
		if (res == -1 || res < temp)res = temp;
	}
	cout << res;
	return 0;
}