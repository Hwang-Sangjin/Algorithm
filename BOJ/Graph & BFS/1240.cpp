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

using namespace std;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

vector<vector<pair<int, int>>> m(10002);

int dist[10002];

int bfs(int s, int e)
{
  queue<int> q;
  q.push(s);
  dist[s] = 0;

  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    for (auto next : m[t])
    {
      if (dist[next.first] >= 0)
        continue;
      dist[next.first] = dist[t] + next.second;
      q.push(next.first);
    }
  }
  return dist[e];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  int x, y, dis;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> x >> y >> dis;
    m[x].push_back({y, dis});
    m[y].push_back({x, dis});
  }

  int start, end;
  while (M--)
  {
    memset(dist, -1, sizeof(dist));
    cin >> start >> end;
    cout << bfs(start, end) << '\n';
  }

  return 0;
}
