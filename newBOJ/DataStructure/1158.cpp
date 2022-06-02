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

using namespace std;

void Josephus(int N, int K)
{
  queue<int> q;
  vector<int> res;

  for (int i = 1; i <= N; i++)
  {
    q.push(i);
  }

  int cnt = 1;
  while (!q.empty())
  {
    int t = q.front();
    q.pop();

    if (cnt == K)
    {
      res.push_back(t);
      cnt = 1;
      continue;
    }
    q.push(t);
    cnt++;
  }
  cout << '<';
  for (int i = 0; i < res.size() - 1; i++)
  {
    cout << res[i] << ", ";
  }
  cout << res[res.size() - 1] << '>';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  Josephus(N, K);

  return 0;
}
