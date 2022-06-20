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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  int fiveCnt = N / 5;
  int remain = (N % 5) % 2;

  while (remain != 0)
  {
    if (fiveCnt == 0)
    {
      cout << -1;
      return 0;
    }
    fiveCnt--;
    remain = (N - fiveCnt * 5) % 2;
  }
  cout << fiveCnt + (N - fiveCnt * 5) / 2;

  return 0;
}
