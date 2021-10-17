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


#define INF 100000000;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;
int V, E, StartPoint, EndPoint;

vector<pair<int, int>> Ver[1002];
int Dist[1002];
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void djikstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ StartPoint,0 });
	Dist[StartPoint] = 0;

	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		int tindex = t.first;
		int tcost = t.second;

		if (Dist[tindex] < tcost) continue;

		for (int i = 0; i < Ver[tindex].size(); i++) {
			auto n = Ver[tindex][i];
			int nindex = n.first;
			int ncost = n.second;

			if (Dist[nindex] > tcost + ncost) {
				Dist[nindex] = tcost + ncost;
				pq.push({ nindex,Dist[nindex] });
			}
		}
	}
}

int main() {
	cin >> V >> E;
	int s, e, w;
	for (int i = 0; i < E; i++) {
		cin >> s >> e >> w;
		Ver[s].push_back({ e,w });
	}

	for (int i = 1; i <= V; i++) {
		Dist[i] = INF;
	}
	cin >> StartPoint >> EndPoint;

	djikstra();

	cout << Dist[EndPoint];

	return 0;
}