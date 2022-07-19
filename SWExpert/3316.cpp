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

long long dp[10002][16];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  long long N, M;
  cin >> T;

  int level = 1;

  while (T--)
  {

    string club;
    cin >> club;

    long long case_cnt = 0;
    memset(dp, 0, sizeof(dp));

    for (int day = 0; day < club.size(); day++)
    {
      int admin = 1 << (club[day] - 'A');

      for (int i = 1; i < 16; i++)
      {
        if (day == 0)
        {
          if ((i & admin) != 0 && (i & 1) != 0)
          {
            dp[day][i] = 1;
          }
        }
        else
        {
          if (dp[day - 1][i] != 0)
          {
            for (int j = 1; j < 16; j++)
            {
              // 전날 나온 사람이 오늘도 나오고 (i & j != 0)
              // 오늘 나온 사람이 관리자인 경우 count (j & admin != 0)
              if ((i & j) != 0 && (j & admin) != 0)
              {
                dp[day][j] += dp[day - 1][i];
                dp[day][j] %= 1000000007;
              }
            }
          }
        }
      }
    }
    for (int i = 1; i < 16; i++)
    {
      case_cnt += dp[club.size() - 1][i];
      case_cnt %= 1000000007;
    }

    cout << "#" << level << " " << case_cnt << '\n';
    level++;
  }

  return 0;
}