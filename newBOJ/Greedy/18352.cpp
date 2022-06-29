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

int N, M, K, X;
vector<vector<int>> m(300002);
int res[300002];

void Dijkstra()
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, X});
  memset(res, -1, sizeof(res));
  res[X] = 0;

  while (!pq.empty())
  {
    auto t = pq.top();
    pq.pop();
    int tcnt = t.first;
    int ti = t.second;

    for (auto k : m[ti])
    {
      if (res[k] == -1 || tcnt + 1 < res[k])
      {
        res[k] = tcnt + 1;
        pq.push({tcnt + 1, k});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K >> X;

  int a, b;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    m[a].push_back(b);
  }

  Dijkstra();

  bool check = false;
  for (int i = 1; i <= N; i++)
  {
    if (res[i] == K)
    {
      cout << i << '\n';
      check = true;
    }
  }
  if (!check)
    cout << -1;

  return 0;
}
