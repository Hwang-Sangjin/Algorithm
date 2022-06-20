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

vector<pair<int, int>> v(51);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  vector<pair<int, int>> board;

  s += '.';
  int n = s.length();

  v[2] = {0, 1};
  v[4] = {1, 0};

  int start, cnt = 0;
  for (int i = 0; i < n; i++)
  {
    char c = s[i];

    if (c == 'X')
    {
      if (cnt == 0)
      {
        cnt = 1;
        start = i;
      }
      else
      {
        cnt++;
      }
    }
    else
    {
      if (cnt == 0)
      {
        continue;
      }
      else
      {
        board.push_back({start, cnt});
        cnt = 0;
      }
    }
  }

  int maxCnt = 0;
  for (auto t : board)
  {
    maxCnt = max(maxCnt, t.second);
  }

  v[1] = {0, 0};
  for (int k = 2; k <= maxCnt; k++)
  {
    int ACnt = k / 4;
    int remain = (k % 4) % 2;
    bool check = true;

    while (remain != 0)
    {
      if (ACnt == 0)
      {
        check = false;
        break;
      }
      ACnt--;
      remain = (k - ACnt * 4) % 2;
    }
    if (check == false)
      v[k] = {0, 0};
    else
    {
      v[k] = {ACnt, (k - ACnt * 4) / 2};
    }
  }

  for (auto t : board)
  {
    string temp = "";

    if (v[t.second].first == 0 && v[t.second].second == 0)
    {
      cout << -1;
      return 0;
    }
    for (int i = 0; i < v[t.second].first; i++)
    {
      temp += "AAAA";
    }
    for (int i = 0; i < v[t.second].second; i++)
    {
      temp += "BB";
    }
    s.replace(t.first, t.second, temp);
    // cout << t.first << ' ' << v[t.second].first << ' ' << v[t.second].second<<'\n';
  }
  cout << s.substr(0, s.length() - 1);

  return 0;
}
