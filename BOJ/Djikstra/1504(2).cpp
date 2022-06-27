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
#include <set>
#include <map>
#include <sstream>

#define INF 20000000 + 1;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;

int V, E, V1, V2;
vector<vector<pair<int, int>>> m(802);
vector<int> res(802);

void Dijkstra(int K)
{
  for (int i = 1; i <= V; i++)
  {
    res[i] = INF;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, K});
  res[K] = 0;

  while (!pq.empty())
  {
    auto t = pq.top();
    pq.pop();
    int dist = t.first;
    int now = t.second;

    for (auto i : m[now])
    {
      int cost = dist + i.second;
      int next = i.first;

      if (cost < res[next])
      {
        res[next] = cost;
        pq.push({cost, next});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int u, v, w;
  int sToV1, sToV2;
  int V1ToF, V2ToF, V1ToV2;
  cin >> V >> E;

  for (int i = 0; i < E; i++)
  {
    cin >> u >> v >> w;
    m[u].push_back({v, w});
    m[v].push_back({u, w});
  }
  cin >> V1 >> V2;
  Dijkstra(1);
  sToV1 = res[V1];
  sToV2 = res[V2];
  Dijkstra(V1);
  V1ToV2 = res[V2];
  V1ToF = res[V];
  Dijkstra(V2);
  V2ToF = res[V];

  int f = sToV1 + V1ToV2 + V2ToF;
  int s = sToV2 + V1ToV2 + V1ToF;

  int ans = min(f, s);
  if (ans >= 20000001)
    cout << -1;
  else
    cout << ans;

  return 0;
}
