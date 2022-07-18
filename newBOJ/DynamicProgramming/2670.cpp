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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  float N;
  cin >> N;

  vector<float> v(N);

  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }

  vector<float> dp(N);
  dp[0] = v[0];
  float res = 0;

  for (int i = 1; i < N; i++)
  {
    if (dp[i - 1] > 1)
    {
      dp[i] = dp[i - 1] * v[i];
    }
    else
    {
      dp[i] = v[i];
    }
    res = max(res, dp[i]);
  }

  printf("%.3f", roundf(res * 1000) / 1000);

  return 0;
}
