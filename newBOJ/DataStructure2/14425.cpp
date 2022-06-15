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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  set<string> S;
  string t;
  while (N--)
  {
    cin >> t;
    S.insert(t);
  }

  int res = 0;
  while (M--)
  {
    cin >> t;

    if (S.find(t) != S.end())
    {
      res++;
    }
  }
  cout << res;

  return 0;
}
