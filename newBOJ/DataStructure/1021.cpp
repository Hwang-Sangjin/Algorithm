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
  int N, M, temp;
  int res = 0;
  cin >> N >> M;

  vector<int> arr(M);

  for (int i = 0; i < M; i++)
  {
    cin >> arr[i];
  }

  deque<int> dq;

  for (int i = 1; i <= N; i++)
  {
    dq.push_back(i);
  }

  for (int i = 0; i < M; i++)
  {
    int t = arr[i];
    int index = 0;

    for (int i = 0; i < dq.size(); i++)
    {
      if (dq[i] == t)
      {
        index = i;
        break;
      }
    }

    bool direction = (index <= dq.size() / 2) ? (true) : (false);

    if (direction)
    {
      for (int i = 0; i < index; i++)
      {
        dq.push_back(dq.front());
        dq.pop_front();
        res++;
      }
    }
    else
    {
      for (int i = 0; i < dq.size() - index; i++)
      {
        dq.push_front(dq.back());
        dq.pop_back();
        res++;
      }
    }
    dq.pop_front();
  }
  cout << res;

  return 0;
}
