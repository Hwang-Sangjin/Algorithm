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

int m[102][102];
bool v[102][102];
set<int> s;

int N;
void BFS(int x, int y, int level)
{
  queue<pair<int, int>> q;
  q.push({x, y});
  v[x][y] = true;

  while (!q.empty())
  {
    auto t = q.front();
    int ti = t.first;
    int tj = t.second;
    q.pop();

    for (int k = 0; k < 4; k++)
    {
      int ni = ti + di[k];
      int nj = tj + dj[k];

      if (ni < 0 || nj < 0 || ni >= N || nj >= N || v[ni][nj] || m[ni][nj] <= level)
        continue;
      q.push({ni, nj});
      v[ni][nj] = true;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  for (int x = 1; x <= T; x++)
  {
    cin >> N;

    s.clear();
    memset(m, 0, sizeof(m));

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> m[i][j];
        s.insert(m[i][j]);
      }
    }
    int cnt = 0;
    int res = 0;

    for (auto t : s)
    {
      memset(v, false, sizeof(v));
      cnt = 0;
      for (int i = 0; i < N; i++)
      {
        for (int j = 0; j < N; j++)
        {
          if (v[i][j] || m[i][j] <= t)
            continue;
          BFS(i, j, t);
          cnt++;
        }
      }
      res = max(res, cnt);
    }
    if (res == 0)
      res = 1;
    cout << x << ' ' << res << '\n';
  }

  return 0;
}
