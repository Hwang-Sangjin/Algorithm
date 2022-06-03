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

int card(int N)
{
  queue<int> q;

  for (int i = 1; i <= N; i++)
  {
    q.push(i);
  }

  bool check = false;
  while (q.size() != 1)
  {
    if (check)
    {
      int t = q.front();

      q.push(t);
      q.pop();
      check = false;
    }
    else
    {
      q.pop();
      check = true;
    }
  }
  return q.front();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  cout << card(N);

  return 0;
}
