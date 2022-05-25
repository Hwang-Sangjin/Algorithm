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
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
  int answer = 0;
  int N;
  cin >> N;
  int temp;
  while (N--)
  {
    cin >> temp;

    pq.push(temp);
  }

  while (pq.size() != 1)
  {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    answer += a + b;
    pq.push(a + b);
  }
  cout << answer;

  return 0;
}
