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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  map<string, long long> tree;

  double total = 0;
  while (getline(cin, s))
  {
    tree[s]++;
    total++;
  }

  cout << fixed;
  cout.precision(4);
  for (auto t : tree)
  {
    cout << t.first << ' ' << t.second * 100 / total << '\n';
  }
  return 0;
}
