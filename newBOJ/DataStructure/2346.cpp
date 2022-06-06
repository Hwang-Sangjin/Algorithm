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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, t;

  deque<pair<int, int>> dq;

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> t;
    dq.push_back({t, i});
  }

  while (!dq.empty())
  {
    auto t = dq.front();
    int v = t.first;
    int index = t.second;
    cout << index << ' ';
    dq.pop_front();

    if (v > 0)
    {
      v--;
      while (!v == 0)
      {
        dq.push_back(dq.front());
        dq.pop_front();
        v--;
      }
    }
    else
    {
      while (!v == 0)
      {
        dq.push_front(dq.back());
        dq.pop_back();
        v++;
      }
    }
  }

  return 0;
}
