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
  ;

  while (T--)
  {
    int N, temp;
    cin >> N;

    priority_queue<int> pq;

    while (N--)
    {
      cin >> temp;
      pq.push(temp);
    }

    vector<int> v;
    v.push_back(pq.top());
    pq.pop();

    priority_queue<int, vector<int>, greater<int>> rev;
    bool check = true;
    while (!pq.empty())
    {
      if (check)
      {
        check = false;
        v.push_back(pq.top());
        pq.pop();
      }
      else
      {
        check = true;
        rev.push(pq.top());
        pq.pop();
      }
    }
    while (!rev.empty())
    {
      v.push_back(rev.top());
      rev.pop();
    }

    int vN = v.size();
    int res = abs(v[0] - v[vN - 1]);

    for (int i = 0; i < vN - 1; i++)
    {
      res = max(res, abs(v[i] - v[i + 1]));
    }
    cout << res << '\n';
  }

  return 0;
}
