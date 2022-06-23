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
  vector<int> v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end(), desc);

  long long res = 0;
  for (int i = 0; i < N; i++)
  {
    if (i % 3 == 2)
    {
      continue;
    }
    res += v[i];
  }
  cout << res;
  return 0;
}
