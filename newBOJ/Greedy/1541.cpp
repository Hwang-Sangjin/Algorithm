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

  string s;
  cin >> s;
  s += ' ';

  int res = 0;
  string num = "";
  bool isMinus = false;

  for (int i = 0; i <= s.length(); i++)
  {
    char c = s[i];

    if (c == '-' || c == '+' || i == s.length())
    {
      if (isMinus)
      {
        res -= stoi(num);
      }
      else
      {
        res += stoi(num);
      }
      num = "";
    }
    else
    {
      num += c;
    }
    if (c == '-' && isMinus == false)
    {
      isMinus = true;
    }
  }

  cout << res;

  return 0;
}
