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
  int N;
  cin >> N;

  int res = 0;
  string s;
  while (N--)
  {
    cin >> s;

    if (s.length() % 2 != 0)
      continue;

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
      char t = s[i];

      if (st.empty())
      {
        st.push(t);
        continue;
      }

      if (st.top() == t)
        st.pop();
      else
        st.push(t);
    }

    if (st.empty())
    {
      res++;
    }
  }
  cout << res;

  return 0;
}
