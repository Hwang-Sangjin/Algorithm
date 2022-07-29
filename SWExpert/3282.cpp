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

int dp[101][100001];
int w[101]; // 물건의 무게
int v[101];

int main(int argc, char **argv)
{
  int test_case;
  int T;
  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case)
  {
    int N, K, ans = 0;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
      cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= K; j++)
      {
        if (j < w[i])
        {
          dp[i][j] = dp[i - 1][j];
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
      }
    }
    cout << '#' << test_case << ' ' << dp[N][K] << '\n';
  }
  return 0;
}