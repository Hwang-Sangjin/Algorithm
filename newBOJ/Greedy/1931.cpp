//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int n;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b)
{
  if (a.second <= b.second)
  {
    if (a.second == b.second)
    {
      return a.first < b.first;
    }
    return a.second < b.second;
  }
  return a.second < b.second;
}

int main()
{
  cin >> n;

  int x, y;

  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }

  sort(v.begin(), v.end(), compare);

  int cnt = 0;
  int available = 0;
  for (int i = 0; i < n; i++)
  {
    if (available <= v[i].first)
    {
      available = v[i].second;
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}