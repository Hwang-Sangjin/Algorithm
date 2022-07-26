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

#define INF 987654321

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;

int m[18][18];
int N;
int res = -1;
int dp[18][1 << 16];

int DFS(int cur, int V)
{
  if (V == (1 << N) - 1)
  {
    if (m[cur][0] == 0)
      return INF;
    else
      return m[cur][0];
  }

  if (dp[cur][V] != -1)
    return dp[cur][V];

  dp[cur][V] = INF;

  for (int i = 0; i < N; i++)
  {
    if (m[cur][i] == 0)
      continue;
    if ((V) & (1 << i))
      continue;
    dp[cur][V] = min(dp[cur][V], m[cur][i] + DFS(i, V | (1 << i)));
  }
  return dp[cur][V];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> m[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << DFS(0, 1);

  return 0;
}
