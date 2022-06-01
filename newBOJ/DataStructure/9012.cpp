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

string checkBrackets(string t)
{
  stack<int> st;
  // ( 는 1로
  // ) 은 0으로
  bool res = true;
  // true이면 가능한 상태
  // false이면 불가능한 상태

  for (int i = 0; i < t.length(); i++)
  {
    if (t[i] == '(')
    {
      st.push(1);
    }
    else if (t[i] == ')')
    {
      if (st.empty())
      {
        res = false;
        break;
      }
      else
      {
        if (st.top() == ')')
        {
          res = false;
          break;
        }
        else
        {
          st.pop();
        }
      }
    }
  }

  if (!st.empty())
  {
    res = false;
  }

  return res ? "YES" : "NO";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  string t;
  while (T--)
  {
    cin >> t;

    cout << checkBrackets(t) << '\n';
  }

  return 0;
}
