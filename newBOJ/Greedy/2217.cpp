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
  int res = 0;

  vector<int> rope(N);

  for (int i = 0; i < N; i++)
  {
    cin >> rope[i];
  }

  sort(rope.begin(), rope.end());

  for (int i = 0; i < N; i++)
  {
    int cnt = N - i;
    int temp = cnt * rope[i];
    res = max(res, temp);
  }
  cout << res;

  return 0;
}
