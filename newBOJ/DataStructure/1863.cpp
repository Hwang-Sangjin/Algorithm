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

  stack<int> st;

  int N, x, y;
  cin >> N;
  int res = 0;

  while (N--)
  {
    cin >> x >> y;

    while (!st.empty() && st.top() > y)
    {
      if (st.top())
        res++;
      st.pop();
    }
    if (!st.empty() && st.top() == y)
      continue;

    st.push(y);
  }

  while (!st.empty())
  {
    if (st.top())
      res++;
    st.pop();
  }

  cout << res;
  return 0;
}
