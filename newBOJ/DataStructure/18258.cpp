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

deque<int> dq;

void push()
{
  int t;
  cin >> t;
  dq.push_back(t);
}

int pop()
{
  if (dq.empty())
  {
    return -1;
  }
  else
  {
    int t = dq.front();
    dq.pop_front();
    return t;
  }
}

int size()
{
  return dq.size();
}

int empty()
{
  if (dq.empty())
    return 1;
  return 0;
}

int front()
{
  if (dq.empty())
    return -1;

  int t = dq.front();
  return t;
}

int back()
{
  if (dq.empty())
    return -1;

  int t = dq.back();
  return t;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  string t;
  while (N--)
  {
    cin >> t;

    if (t == "push")
    {
      push();
    }
    else if (t == "pop")
    {
      cout << pop() << '\n';
    }
    else if (t == "size")
    {
      cout << size() << '\n';
    }
    else if (t == "empty")
    {
      cout << empty() << '\n';
    }
    else if (t == "front")
    {
      cout << front() << '\n';
    }
    else if (t == "back")
    {
      cout << back() << '\n';
    }
  }

  return 0;
}
