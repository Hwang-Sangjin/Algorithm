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

#define INF 20000000 + 1;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  string s;
  cin >> s;

  string temp = "";
  s += '0';

  char c = s[0];
  for (int i = 1; i < s.length(); i++)
  {
    if (c == s[i])
      continue;
    else
    {
      c = s[i];
      temp += s[i - 1];
    }
  }

  int Bcnt = 0;
  int Rcnt = 0;

  for (int i = 0; i < temp.length(); i++)
  {
    if (temp[i] == 'B')
      Bcnt++;
    else
      Rcnt++;
  }

  int res = (Bcnt >= Rcnt) ? (1 + Rcnt) : (1 + Bcnt);
  cout << res;

  return 0;
}
