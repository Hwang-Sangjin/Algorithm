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

  int N;
  cin >> N;
  int operCnt = N - 1;

  string expression;
  cin >> expression;

  vector<int> v;

  int t;
  for (int i = 0; i < N; i++)
  {
    cin >> t;
    v.push_back(t);
  }

  stack<double> st;

  for (int i = 0; i < expression.length(); i++)
  {
    char c = expression[i];

    if (c >= 65 && c <= 90)
    {
      st.push(v[c - 65]);
    }
    else
    {
      double s = st.top();
      st.pop();
      double f = st.top();
      st.pop();

      if (c == '+')
      {
        st.push(f + s);
      }
      else if (c == '-')
      {
        st.push(f - s);
      }
      else if (c == '*')
      {
        st.push(f * s);
      }
      else if (c == '/')
      {
        st.push(f / s);
      }
    }
  }
  printf("%.2f", st.top());

  return 0;
}
