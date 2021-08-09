#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue> 
#include <stack>
#include <deque>

using namespace std;
int V, E, P;
vector<pair<int, int>> map[5002];
int dist[5002];

struct cmp { // swap을 진행하는 조건
	bool operator()(pair<int,int> a, pair<int, int> b) {
		return a.second > b.second; // 오름 차순 정렬
	}
};

int dijkstra(int start, int dest) {
	int total = 0;
	memset(dist, -1, sizeof(dist));
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> q;
	q.push({ start, 0 });

	while (!q.empty()) {
		auto t = q.top();
		q.pop();
		int ti = t.first;
		int tcnt = t.second;

		/*for (int i = 1; i <= V; i++) {
			cout << dist[i] << ' ';
		}
		cout << '\n';*/

		if (ti == dest) {
			total = tcnt;
			break;
		}

		for (int i = 0; i < map[ti].size(); i++) {
			int ni = map[ti][i].second;
			int ncnt = map[ti][i].first;
			if (dist[ni] == -1 ||dist[ni] > dist[ti] + ncnt) {
				dist[ni] = dist[ti] + ncnt;
				q.push({ ni,dist[ti] + ncnt });
			}
		}
	}
	return total;
}

int main()
{
	cin >> V >> E >> P;

	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		map[a].push_back({ c,b });
		map[b].push_back({ c,a });
	}

	int res1 = dijkstra(1, V);
	int res2 = dijkstra(1, P) + dijkstra(P, V);

	cout << (res1 == res2 ? "SAVE HIM" : "GOOD BYE");
}
