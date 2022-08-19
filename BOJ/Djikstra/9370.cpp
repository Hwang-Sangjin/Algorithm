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
#define INF 987654321;
#define MAX 2010

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;
int n, m, t;
int s, g, h, GH;
int S[2001];
int G[2001];
int H[2001];

vector<vector<pair<int, int>>> v(2001);

void Dijkstra(int Start, int A[2001])
{
  priority_queue<pair<int, int>> pq;
  pq.push({0, Start});
  A[Start] = 0;

  while (!pq.empty())
  {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    for (auto tt : v[cur])
    {
      int next = tt.first;
      int ncost = tt.second;

      if (A[next] > cost + ncost)
      {
        A[next] = cost + ncost;
        pq.push({A[next], next});
      }
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

  while (T--)
  {
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    vector<int> nomiee;

    for (int i = 0; i < n + 1; i++)
    {
      v[i].clear();
      S[i] = INF;
      G[i] = INF;
      H[i] = INF;
    }

    int temp;
    int a, b, d;
    for (int i = 0; i < m; i++)
    {
      cin >> a >> b >> d;
      v[a].push_back({b, d});
      v[b].push_back({a, d});
    }
    for (int i = 0; i < t; i++)
    {
      cin >> temp;
      nomiee.push_back(temp);
    }

    Dijkstra(s, S);
    Dijkstra(g, G);
    GH = G[h];
    Dijkstra(h, H);

    sort(nomiee.begin(), nomiee.end());
    for (auto Dest : nomiee)
    {
      if (S[Dest] == S[g] + GH + H[Dest] || S[Dest] == S[h] + GH + G[Dest])
        cout << Dest << ' ';
    }
    cout << '\n';
  }

  return 0;
}