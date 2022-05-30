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

using namespace std;

bool v[1002];
int N;
int ans = 0;
int d[4] = {1, 5, 10, 50};

void go(int index, int res, int kIndex)
{
  // cout << index << ' ' << res << '\n';
  if (index == N)
  {
    if (v[res] == false)
    {
      // cout << res << '\n';
      ans++;
      v[res] = true;
    }
    return;
  }

  for (int k = kIndex; k < 4; k++)
  {
    go(index + 1, res + d[k], k);
  }

  return;
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;

  go(0, 0, 0);

  cout << ans;

  return 0;
}
