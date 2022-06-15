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

bool isNumber(string s)
{
  char c = s[0];

  if (c >= '0' && c <= '9')
    return true;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  map<string, int> book;
  map<int, string> book2;

  string s;
  int i = 1;
  while (N--)
  {
    cin >> s;
    book[s] = i;
    book2[i++] = s;
  }

  while (M--)
  {
    cin >> s;

    if (isNumber(s))
    {
      int t = stoi(s);
      cout << book2[t] << '\n';
    }
    else
    {
      cout << book[s] << '\n';
    }
  }

  return 0;
}
