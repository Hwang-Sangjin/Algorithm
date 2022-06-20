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
#include <sstream>

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--)
  {
    priority_queue<int, vector<int>, less<int>> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;
    map<int, int> m;
    int k;
    cin >> k;
    int cnt = 0;

    char c;
    int t;
    while (k--)
    {
      cin >> c >> t;
      if (c == 'I')
      {
        maxPq.push(t);
        minPq.push(t);
        m[t]++;
        cnt++;
      }
      else
      {
        if (cnt == 0)
          continue;
        if (t == -1)
        {
          while (!minPq.empty())
          {
            int temp = minPq.top();
            minPq.pop();
            cnt--;
            if (m[temp])
            {
              // cout << temp << '\n';
              m[temp]--;

              break;
            }
          }
        }
        else
        {
          while (!maxPq.empty())
          {
            int temp = maxPq.top();
            maxPq.pop();
            cnt--;
            if (m[temp])
            {
              // cout << temp << '\n';
              m[temp]--;
              break;
            }
          }
        }
      }
    }

    while (!maxPq.empty() && m[maxPq.top()] == 0)
    {
      maxPq.pop();
    }
    while (!minPq.empty() && m[minPq.top()] == 0)
    {
      minPq.pop();
    }

    if (maxPq.empty() || minPq.empty())
    {
      cout << "EMPTY\n";
    }
    else
    {
      cout << maxPq.top() << ' ' << minPq.top() << '\n';
    }
  }

  return 0;
}
