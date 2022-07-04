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

  int N, x, a;
  cin >> N;
  long long sum = 0;

  vector<pair<int, int>> vil(N + 1);
  for (int i = 1; i <= N; i++)
  {
    cin >> x >> a;
    vil[i] = {x, a};
    sum += a;
  }

  sort(vil.begin() + 1, vil.end());

  long long cur = 0;

  for (int i = 1; i <= N; i++)
  {
    cur += vil[i].second;
    if (cur >= (sum + 1) / 2)
    {
      cout << vil[i].first;
      break;
    }
  }

  return 0;
}
