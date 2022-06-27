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

#define INF 1e9;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;

int V, E, K;
vector<vector<pair<int, int>>> m(20001);
vector<int> res(20001);

void Dijkstra()
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

  cin >> V >> E >> K;

  for (int i = 0; i < E; i++)
  {
    cin >> u >> v >> w;
    m[u].push_back({v, w});
  }

  Dijkstra();

  for (int i = 1; i <= V; i++)
  {
    if (res[i] == 1e9)
      cout << "INF\n";
    else
      cout << res[i] << '\n';
  }

  return 0;
}
