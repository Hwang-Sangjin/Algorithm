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

  stack<pair<int, int>> s; // pair<int, int> : index, height
  int num, height;
  cin >> num;

  for (int i = 0; i < num; i++)
  {
    cin >> height;

    while (!s.empty())
    {
      if (height < s.top().second)
      {
        cout << s.top().first << ' ';
        break;
      }
      s.pop();
    }
    if (s.empty())
    {
      cout << 0 << ' ';
    }
    s.push({i + 1, height});
  }

  return 0;
}
