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

struct Point
{
  int x;
  int state;
  int id;
};

bool compare(Point &a, Point &b)
{
  return a.x < b.x;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<Point> v;

  int x, r;
  for (int i = 0; i < N; i++)
  {
    cin >> x >> r;

    v.push_back({x - r, 0, i});
    v.push_back({x + r, 1, i});
  }

  sort(v.begin(), v.end(), compare);

  stack<int> st;

  for (auto t : v)
  {
    if (t.state == 0)
      st.push(t.id);
    else
    {
      if (st.top() != t.id)
      {
        cout << "NO" << '\n';
        return 0;
      }
      else
      {
        st.pop();
      }
    }
  }
  if (!st.empty())
    cout << "NO" << '\n';
  else
    cout << "YES" << '\n';

  return 0;
}
