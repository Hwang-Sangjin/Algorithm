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

int pr(char c)
{
  if (c == '(')
    return 0;
  if (c == '+' || c == '-')
    return 1;
  if (c == '*' || c == '/')
    return 2;
}

int main()
{

  string s;
  stack<char> st;

  cin >> s;

  for (int i = 0; i < s.length(); i++)
  {
    char t = s[i];

    if (t >= 'A' && t <= 'Z')
    {
      cout << t;
    }
    else
    {
      if (t == '(')
      {
        st.push(t);
      }
      else if (t == ')')
      {
        while (st.top() != '(')
        {
          cout << st.top();
          st.pop();
        }
        st.pop();
      }
      else
      {
        while (!st.empty() && pr(st.top()) >= pr(t))
        {
          cout << st.top();
          st.pop();
        }
        st.push(t);
      }
    }
  }
  while (!st.empty())
  {
    cout << st.top();
    st.pop();
  }

  return 0;
}
