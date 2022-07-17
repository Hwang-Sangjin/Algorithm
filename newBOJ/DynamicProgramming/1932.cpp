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
int m[502][502];
int dp[502][502];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cin >> m[i][j];
    }
  }

  dp[1][1] = m[1][1];
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      if (j == 1)
      {
        dp[i][j] = dp[i - 1][j] + m[i][j];
      }
      else if (j == i)
      {
        dp[i][j] = dp[i - 1][j - 1] + m[i][j];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + m[i][j];
      }
    }
  }

  int res = 0;
  for (int i = 1; i <= N; i++)
  {
    res = max(res, dp[N][i]);
  }
  cout << res;

  return 0;
}
