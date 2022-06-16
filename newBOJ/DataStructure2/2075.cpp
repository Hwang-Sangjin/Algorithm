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
  int N, t;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < N; i++)
  {

    if (i == 0)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> t;
        pq.push(t);
      }
    }
    else
    {
      for (int j = 0; j < N; j++)
      {
        cin >> t;
        pq.push(t);
      }
      for (int j = 0; j < N; j++)
      {
        pq.pop();
      }
    }
  }
  cout << pq.top();
  return 0;
}