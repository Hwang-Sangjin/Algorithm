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

  string pipe;

  cin >> pipe;

  int res = 0;
  stack<int> st;
  for (int i = 0; i < pipe.length(); i++)
  {
    char c = pipe[i];

    if (c == '(')
    {
      st.push(0);
    }
    else
    {
      if (pipe[i - 1] == '(')
      {
        st.pop();
        res += st.size();
      }
      else
      {
        st.pop();
        res++;
      }
    }
  }
  cout << res;
  return 0;
}
