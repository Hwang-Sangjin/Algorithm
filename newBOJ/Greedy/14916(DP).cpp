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

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;

int dp[500002];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  dp[2] = 1;
  dp[5] = 1;

  for (int i = 4; i <= N; i++)
  {
    if (dp[i - 2] != 0)
    {
      dp[i] = dp[i - 2] + 1;
    }
    if (dp[i - 5] != 0)
    {
      dp[i] = min(dp[i], dp[i - 5] + 1);
    }
  }
  if (dp[N] == 0)
    dp[N] = -1;
  cout << dp[N];

  return 0;
}
