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

int dp[100002][2];
int dis[100002];

int main()
{
  int N;
  cin >> N;

  vector<int> building(N);
  memset(dis, -1, sizeof(dis));

  for (int i = 0; i < N; i++)
  {
    cin >> building[i];
  }

  stack<pair<int, int>> left;
  stack<pair<int, int>> right;

  for (int i = 0; i < N; i++)
  {
    int l = i;
    int r = N - 1 - i;

    if (left.empty())
      left.push({building[l], l});
    else
    {
      while (1)
      {
        if (left.empty())
          break;

        if (left.top().first > building[l])
        {
          break;
        }
        else
        {
          left.pop();
        }
      }
      dp[l][0] = left.size();

      if (dp[l][0] != 0)
      {
        if (dis[l] == -1)
          dis[l] = left.top().second;
        else
        {
          dis[l] = (abs(dis[l] - l) >= abs(left.top().second - l)) ? (left.top().second) : (dis[l]);
        }
      }

      left.push({building[l], l});
    }

    if (right.empty())
      right.push({building[r], r});
    else
    {
      while (1)
      {
        if (right.empty())
          break;

        if (right.top().first > building[r])
        {
          break;
        }
        else
        {
          right.pop();
        }
      }
      dp[r][1] = right.size();

      if (dp[r][1] != 0)
      {
        if (dis[r] == -1)
          dis[r] = right.top().second;
        else
        {
          dis[r] = (abs(dis[r] - r) > abs(right.top().second - r)) ? (right.top().second) : (dis[r]);
        }
      }

      right.push({building[r], r});
    }
  }
  for (int i = 0; i < N; i++)
  {
    int t = dp[i][0] + dp[i][1];

    if (t == 0)
    {
      cout << t << '\n';
    }
    else
    {
      cout << t << ' ' << dis[i] + 1 << '\n';
    }
  }

  return 0;
}