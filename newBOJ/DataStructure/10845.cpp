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
queue<int> q;
int b;

void push()
{
  int t;
  cin >> t;
  q.push(t);
  b = t;
}

int pop()
{
  if (q.empty())
  {
    return -1;
  }
  else
  {
    int t = q.front();
    q.pop();
    return t;
  }
}

int size()
{
  return q.size();
}

int empty()
{
  if (q.empty())
    return 1;
  return 0;
}

int front()
{
  if (q.empty())
    return -1;

  int t = q.front();
  return t;
}

int back()
{
  if (q.empty())
    return -1;

  int t = q.back();
  return t;
}

int main()
{
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
