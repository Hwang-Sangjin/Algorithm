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
int N, M;
vector<int> truth;
bool connection[52][52];
bool v[52];
vector<vector<int>> p;

void bfs(int index)
{
  queue<int> q;
  q.push(index);
  v[index] = true;

  while (!q.empty())
  {
    auto t = q.front();
    q.pop();

    for (int i = 1; i <= N; i++)
    {
      if (connection[t][i])
      {
        if (v[i])
          continue;
        q.push(i);
        v[i] = true;
      }
    }
  }
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int res = 0;
  cin >> N >> M;

  int T, temp;
  cin >> T;

  while (T--)
  {
    cin >> temp;
    truth.push_back(temp);
  }

  for (int i = 0; i < M; i++)
  {
    cin >> temp;
    int t;
    vector<int> party;
    while (temp--)
    {
      cin >> t;
      party.push_back(t);
    }
    p.push_back(party);
    for (int i = 0; i < party.size() - 1; i++)
    {
      for (int j = i + 1; j < party.size(); j++)
      {
        connection[party[i]][party[j]] = true;
        connection[party[j]][party[i]] = true;
      }
    }
  }

  for (auto t : truth)
  {
    bfs(t);
  }

  for (auto t : p)
  {
    bool check = false;
    for (auto tt : t)
    {
      if (v[tt])
      {
        check = true;
        break;
      }
    }
    if (check == false)
    {
      res++;
    }
  }
  cout << res;

  return 0;
}
