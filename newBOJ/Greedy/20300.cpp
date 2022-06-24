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

  vector<long long> v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  long long res = 0;
  if (N % 2 == 0)
  {
    long long temp = 0;
    for (int i = 0; i < N; i++)
    {
      temp = v[i] + v[N - 1 - i];
      res = max(temp, res);
    }
  }
  else
  {
    res = v[N - 1];
    long long temp = 0;
    for (int i = 0; i < N - 1; i++)
    {
      temp = v[i] + v[N - 2 - i];
      res = max(temp, res);
    }
  }
  cout << res;

  return 0;
}
