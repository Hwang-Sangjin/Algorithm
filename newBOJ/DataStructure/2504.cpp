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

  string S;
  cin >> S;

  stack<char> st;
  long long res = 0;

  int temp = 1;
  bool check = false;
  for (int i = 0; i < S.length(); i++)
  {
    char t = S[i];

    if (t == '(')
    {
      st.push(t);
      temp *= 2;
    }
    else if (t == '[')
    {
      st.push(t);
      temp *= 3;
    }
    else if (t == ')' && (st.empty() || st.top() != '('))
    {
      check = true;
      break;
    }
    else if (t == ']' && (st.empty() || st.top() != '['))
    {
      check = true;
      break;
    }
    else if (t == ')')
    {
      if (S[i - 1] == '(')
      {
        res += temp;
      }
      st.pop();
      temp /= 2;
    }
    else if (t == ']')
    {
      if (S[i - 1] == '[')
      {
        res += temp;
      }
      st.pop();
      temp /= 3;
    }
  }
  cout << ((check || !st.empty()) ? 0 : res);

  return 0;
}
