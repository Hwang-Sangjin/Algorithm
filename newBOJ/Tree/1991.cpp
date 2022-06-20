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

map<char, pair<char, char>> m;

void pre(char t)
{
  cout << t;
  if (m[t].first != '.')
    pre(m[t].first);
  if (m[t].second != '.')
    pre(m[t].second);
}

void center(char t)
{

  if (m[t].first != '.')
    center(m[t].first);
  cout << t;
  if (m[t].second != '.')
    center(m[t].second);
}

void post(char t)
{

  if (m[t].first != '.')
    post(m[t].first);

  if (m[t].second != '.')
    post(m[t].second);
  cout << t;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  char a, b, c;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b >> c;

    m[a] = {b, c};
  }

  pre('A');
  cout << '\n';
  center('A');
  cout << '\n';
  post('A');

  return 0;
}
