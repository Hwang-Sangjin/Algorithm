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

struct cmp
{
  bool operator()(int a, int b)
  {
    if (abs(a) > abs(b))
    {
      return true;
    }
    else if (abs(a) == abs(b))
    {
      if (a > b)
        return true;
      else
        return false;
    }
    return false;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  priority_queue<int, vector<int>, cmp> pq;

  int N;
  cin >> N;

  int t;
  while (N--)
  {
    cin >> t;
    if (t == 0)
    {
      if (pq.empty())
        cout << 0 << '\n';
      else
      {
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else
    {
      pq.push(t);
    }
  }

  return 0;
}
