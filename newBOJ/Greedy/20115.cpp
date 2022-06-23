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

bool desc(int a, int b)
{
  return a > b;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<double> v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), desc);

  double res = v[0];

  for (int i = 1; i < N; i++)
  {
    res += v[i] / 2;
  }
  cout << res;

  return 0;
}
