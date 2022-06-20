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
vector<vector<int>> v(100002);
int res[100002];

void dfs(int p, int index)
{
  res[index] = p;
  if (v[index].size() == 1)
  {
    return;
  }
  else
  {
    for (auto t : v[index])
    {
      if (t == p)
        continue;
      dfs(index, t);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  v[1].push_back(0);
  int x, y;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  dfs(0, 1);

  for (int i = 2; i <= N; i++)
  {
    cout << res[i] << '\n';
  }

  return 0;
}
