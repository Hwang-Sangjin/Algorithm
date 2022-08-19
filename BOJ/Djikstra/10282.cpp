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
#define MAX (10001)
#define INF (987654321)

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;
int n, d, c;

int res[MAX];
int resCnt, resSec;

void Dijkstra(vector<pair<int, int>> m[])
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, c});
  res[c] = 0;
  resCnt = 0;
  resSec = 0;

  while (!pq.empty())
  {
    auto t = pq.top();
    pq.pop();
    int tsec = t.first;
    int tindex = t.second;

    if (res[tindex] < tsec)
      continue;

    for (auto tt : m[tindex])
    {
      int nindex = tt.first;
      int nsec = tt.second;

      if (res[nindex] > tsec + nsec)
      {
        res[nindex] = tsec + nsec;
        pq.push({tsec + nsec, nindex});
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (res[i] != INF)
    {
      resSec = max(resSec, res[i]);
      resCnt++;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  int a, b, s;
  while (T--)
  {
    cin >> n >> d >> c;
    vector<pair<int, int>> m[10002];

    for (int i = 0; i < d; i++)
    {
      cin >> a >> b >> s;
      m[b].push_back({a, s});
    }
    fill_n(res, MAX, INF);
    Dijkstra(m);
    cout << resCnt << ' ' << resSec << '\n';
  }

  return 0;
}
