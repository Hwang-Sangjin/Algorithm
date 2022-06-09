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

  string s;
  while (1)
  {
    getline(cin, s);
    if (s == ".")
      break;

    stack<char> st;
    bool available = true;

    for (int i = 0; i < s.length(); i++)
    {
      char t = s[i];
      if (t == '(' || t == '[')
        st.push(t);

      else if (t == ')')
      {
        if (st.empty() || st.top() != '(')
        {
          available = false;
          break;
        }
        else
        {
          st.pop();
        }
      }
      else if (t == ']')
      {
        if (st.empty() || st.top() != '[')
        {
          available = false;
          break;
        }
        else
        {
          st.pop();
        }
      }
    }
    if (!st.empty())
      available = false;

    cout << (available ? "yes" : "no");
    cout << '\n';
  }

  return 0;
}
