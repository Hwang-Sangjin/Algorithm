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

vector<int> m(100002);
bool v[100002];
bool done[1000002];
int cnt = 0;

void DFS(int s)
{
  v[s] = true;

  int next = m[s];

  if (!v[next])
  {
    DFS(next);
  }
  else if (!done[next])
  {
    for (int i = next; i != s; i = m[i])
    {
      cnt++;
    }
    cnt++;
  }
  done[s] = true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--)
  {
    memset(v, false, sizeof(v));
    memset(done, false, sizeof(done));
    cnt = 0;
    int n;
    cin >> n;

    int t;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
      cin >> t;
      m[i] = t;
    }

    for (int i = 1; i <= n; i++)
    {
      if (!v[i])
        DFS(i);
    }
    cout << n - cnt << '\n';
  }

  return 0;
}
