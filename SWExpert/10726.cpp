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

  int T;
  long long N, M;
  cin >> T;

  int level = 1;

  while (T--)
  {
    cin >> N >> M;

    long long temp = (1 << N) - 1;

    if (temp == (temp & M))
      cout << "#" << level << " ON\n";
    else
      cout << "#" << level << " OFF\n";
    level++;
  }

  return 0;
}