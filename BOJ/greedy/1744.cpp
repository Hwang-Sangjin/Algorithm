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
  priority_queue<int> pos;
  priority_queue<int, vector<int>, greater<int>> neg;

  int zero = 0;
  int res = 0;

  int N, temp;
  cin >> N;

  while (N--)
  {
    cin >> temp;
    if (temp == 1)
    {
      res++;
    }
    else if (temp == 0)
    {
      zero++;
    }
    else if (temp < 0)
    {
      neg.push(temp);
    }
    else
    {
      pos.push(temp);
    }
  }

  int posN = pos.size();

  for (int i = 0; i < posN / 2; i++)
  {
    int a = pos.top();
    pos.pop();
    int b = pos.top();
    pos.pop();
    res += a * b;
  }
  if (!pos.empty())
  {
    res += pos.top();
    pos.pop();
  }

  int negN = neg.size();

  for (int i = 0; i < negN / 2; i++)
  {
    int a = neg.top();
    neg.pop();
    int b = neg.top();
    neg.pop();
    res += a * b;
  }
  if (!neg.empty())
  {
    if (zero == 0)
    {
      res += neg.top();
      neg.pop();
    }
  }
  cout << res;
  return 0;
}
