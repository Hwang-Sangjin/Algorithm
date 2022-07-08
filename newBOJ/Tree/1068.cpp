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

vector<vector<int>> tree(53);

int DFS(int index, int K)
{
  if (index == K)
    return -1;
  if (tree[index].size() == 0)
    return 1;

  int tempRes = 0;
  for (int i = 0; i < tree[index].size(); i++)
  {
    if (DFS(tree[index][i], K) == -1)
    {
      if (tree[index].size() == 1)
      {
        tempRes += 1;
      }
      else
        continue;
    }
    else
    {
      tempRes += DFS(tree[index][i], K);
    }
  }
  return tempRes;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K, temp;

  cin >> N;
  int S = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    if (temp == -1)
    {
      S = i;
      continue;
    }
    tree[temp].push_back(i);
  }
  cin >> K;

  int res = DFS(S, K);

  if (res == -1)
    res = 0;
  cout << res;

  return 0;
}
