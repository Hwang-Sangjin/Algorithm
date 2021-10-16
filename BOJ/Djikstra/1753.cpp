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

#define INF 987654321

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
int V, E, S;
vector<pair<int, int>> Vertext[20002];
int Dist[20002];


void djikstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,S });
	Dist[S] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < Vertext[cur].size(); i++) {
			int next = Vertext[cur][i].first;
			int nCost = Vertext[cur][i].second;

			if (Dist[next] > cost + nCost) {
				Dist[next] = cost + nCost;
				pq.push({ -Dist[next],next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (Dist[i] == INF) cout << "INF\n";
		else cout << Dist[i] << '\n';
	}
}

int main() {
	cin >> V >> E >>S;
	int u, v, w;
	
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		Vertext[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++) Dist[i] = INF;

	djikstra();
	
	return 0;
}