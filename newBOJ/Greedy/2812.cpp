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

  int N, K;
  cin >> N >> K;

  string s;
  cin >> s;

  deque<char> dq;

  for (int i = 0; i < s.length(); i++)
  {
    while (K && !dq.empty() && dq.back() < s[i])
    {
      dq.pop_back();
      K--;
    }
    dq.push_back(s[i]);
  }

  for (int i = 0; i < dq.size() - K; i++)
  {
    cout << dq[i];
  }

  return 0;
}
