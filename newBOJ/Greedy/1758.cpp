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

bool comp(int a, int b)
{
  return a > b;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<int> v(N);

  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end(), comp);

  long long res = 0;
  for (int i = 0; i < N; i++)
  {
    res += (v[i] - (i) < 0) ? 0 : v[i] - (i);
  }
  cout << res;

  return 0;
}
