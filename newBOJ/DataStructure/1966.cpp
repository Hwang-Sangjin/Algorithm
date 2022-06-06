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

  int T;
  cin >> T;

  while (T--)
  {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    int N, t;
    int M;
    cin >> N >> M;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
      cin >> t;
      q.push({t, i});
      pq.push(t);
    }

    while (!q.empty())
    {
      int value = q.front().first;
      int index = q.front().second;
      q.pop();

      if (value == pq.top())
      {
        pq.pop();
        cnt++;
        if (index == M)
        {
          cout << cnt << '\n';
          break;
        }
      }
      else
      {
        q.push({value, index});
      }
    }
  }

  return 0;
}
