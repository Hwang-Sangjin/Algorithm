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
int m[102][102];
bool v[102][102];
int N;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

vector<pair<int, int>> Gpos;

void BFS(int x, int y)
{
  queue<pair<int, int>> q;
  q.push({x, y});
  v[x][y] = true;
  int target = m[x][y];

  while (!q.empty())
  {
    auto t = q.front();
    q.pop();

    int ti = t.first;
    int tj = t.second;

    for (int k = 0; k < 4; k++)
    {
      int ni = ti + di[k];
      int nj = tj + dj[k];
      if (ni < 0 || nj < 0 || ni >= N || nj >= N || v[ni][nj] || m[ni][nj] != target)
        continue;
      q.push({ni, nj});
      v[ni][nj] = true;
    }
  }
}

void RG()
{
  for (auto t : Gpos)
  {
    int ti = t.first;
    int tj = t.second;

    m[ti][tj] = 0;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int cnt = 0, RGcnt = 0;
  string s;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    for (int j = 0; j < N; j++)
    {
      char c = s[j];
      if (c == 'R')
      {
        m[i][j] = 0;
      }
      else if (c == 'B')
      {
        m[i][j] = 1;
      }
      else if (c == 'G')
      {
        m[i][j] = 2;
        Gpos.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (v[i][j] == true)
        continue;
      BFS(i, j);
      cnt++;
    }
  }

  memset(v, false, sizeof(v));
  RG();

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (v[i][j] == true)
        continue;
      BFS(i, j);
      RGcnt++;
    }
  }

  cout << cnt << ' ' << RGcnt;
  return 0;
}
