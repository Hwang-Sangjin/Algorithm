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
int N, M, V1,V2;
vector<pair<int, int>> Ver[1002];
int Dist[1002];
int sToV1, sToV2, V1toV2, V2toV1, V1toe, V2toe;


void djikstra(int s) {
	for (int i = 1; i <= N; i++) {
		Dist[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,s });
	Dist[s] = 0;

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
				pq.push({ tcost + ncost, nindex });
			}
		}
	}
}

int main() {
	int res = -1;
	cin >> N >> M;
	int s, e, w;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> w;
		Ver[s].push_back({ e,w });
		Ver[e].push_back({ s,w });
	}
	cin >> V1 >> V2;
	djikstra(1);
	sToV1 = Dist[V1];
	sToV2 = Dist[V2];
	djikstra(V1);
	V1toV2 = Dist[V2];
	V1toe = Dist[N];
	djikstra(V2);
	V2toV1 = Dist[V1];
	V2toe = Dist[N];

	int firstV1 = sToV1 + V1toV2 + V2toe;
	int firstV2 = sToV2 + V2toV1 + V1toe;

	res = min(firstV1, firstV2);

	if (res >= INF)res = -1;

	cout << res;
	return 0;
}