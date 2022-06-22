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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  long long res = 0;
  long long c_now;

  vector<int> dis(N - 1);
  vector<int> gas(N);

  for (int i = 0; i < N - 1; i++)
  {
    cin >> dis[i];
  }
  for (int i = 0; i < N; i++)
  {
    cin >> gas[i];
  }
  c_now = gas[0];
  res = c_now * dis[0];

  for (int i = 1; i < N - 1; i++)
  {
    if (c_now < gas[i])
    {
      res += c_now * dis[i];
    }
    else
    {
      c_now = gas[i];
      res += c_now * dis[i];
    }
  }
  cout << res;

  return 0;
}
