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

using namespace std;

deque<int> transDQ(string s)
{
  deque<int> answer;

  string buffer;
  s = s.substr(1, s.length() - 2);
  istringstream iss(s);
  while (getline(iss, buffer, ','))
  {
    answer.push_back(stoi(buffer));
  }

  return answer;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    string p;
    int n;
    string x;

    cin >> p >> n >> x;

    deque<int> dq;

    dq = transDQ(x);

    bool e = false;
    bool direction = true;
    for (int i = 0; i < p.length(); i++)
    {
      char t = p[i];

      if (t == 'R')
      {
        direction = !direction;
      }
      else
      {
        if (dq.empty())
        {
          cout << "error\n";
          e = true;
          break;
        }
        else
        {
          if (direction)
          {
            dq.pop_front();
          }
          else
          {
            dq.pop_back();
          }
        }
      }
    }
    if (e)
      continue;
    if (direction)
    {
      cout << "[";
      while (!dq.empty())
      {
        cout << dq.front();
        dq.pop_front();
        if (!dq.empty())
        {
          cout << ",";
        }
      }
      cout << "]";
    }
    else
    {
      cout << "[";
      while (!dq.empty())
      {
        cout << dq.back();
        dq.pop_back();
        if (!dq.empty())
        {
          cout << ",";
        }
      }
      cout << "]";
    }
    cout << '\n';
  }

  return 0;
}
