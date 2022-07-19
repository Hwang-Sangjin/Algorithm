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

  int T, x;
  cin >> T;
  int level = 1;

  while (T--)
  {
    cin >> x;
    int s = 0, ans = 0;
    int i = x, t = 0;

    while (1)
    {
      int k = i;
      while (k)
      {
        t |= (1 << (k % 10));
        k /= 10;
      }
      if (t == 1023)
        break;
      i += x;
    }
    cout << '#' << level << ' ' << i << '\n';
    level++;
  }
  return 0;
}
