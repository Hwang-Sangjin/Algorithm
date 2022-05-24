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
int N, K;
vector<pair<int, int>> v;
vector<int> c;
priority_queue<int> pq;

int main()
{
  long long answer = 0;
  cin >> N >> K;

  int m, t;
  for (int i = 0; i < N; i++)
  {
    cin >> m >> t;
    v.push_back({m, t});
  }

  for (int i = 0; i < K; i++)
  {
    cin >> t;
    c.push_back(t);
  }

  sort(v.begin(), v.end()); // 오름차순

  sort(c.begin(), c.end()); // 오름차순 2 10

  // v- 1,65 2,99 5,23
  // c- 2 10
  // pq- 23
  // answer - 99 + 65
  int index = 0;
  for (int i = 0; i < K; i++)
  {
    while (index < N && v[index].first <= c[i])
    {
      pq.push(v[index++].second);
    }

    if (!pq.empty())
    {
      answer += pq.top();
      pq.pop();
    }
  }
  cout << answer;

  return 0;
}
