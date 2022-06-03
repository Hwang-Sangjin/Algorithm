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

char r[2] = {'-', '+'};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<int> st;
  vector<bool> res;

  int N;
  cin >> N;

  int t;
  int cnt = 1;
  bool available = true;
  for (int i = 1; i <= N; i++)
  {
    cin >> t;

    while (cnt <= t)
    {
      st.push(cnt);
      cnt++;
      res.push_back(true);
    }

    if (st.top() == t)
    {
      st.pop();
      res.push_back(false);
    }
    else
    {
      available = false;
      continue;
    }
  }

  if (available == false)
  {
    cout << "NO";
    return 0;
  }
  for (auto t : res)
  {
    cout << r[t] << '\n';
  }

  return 0;
}
