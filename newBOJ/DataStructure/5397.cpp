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

  int T;
  cin >> T;

  string s;
  while (T--)
  {
    cin >> s;

    deque<char> left;
    deque<char> right;

    for (int i = 0; i < s.length(); i++)
    {
      char c = s[i];

      if (c == '<')
      {
        if (left.empty())
          continue;
        right.push_front(left.back());
        left.pop_back();
      }
      else if (c == '>')
      {
        if (right.empty())
          continue;
        left.push_back(right.front());
        right.pop_front();
      }
      else if (c == '-')
      {
        if (left.empty())
          continue;
        left.pop_back();
      }
      else
      {
        left.push_back(c);
      }
    }
    for (auto t : left)
    {
      cout << t;
    }
    for (auto t : right)
    {
      cout << t;
    }
    cout << '\n';
  }

  return 0;
}
