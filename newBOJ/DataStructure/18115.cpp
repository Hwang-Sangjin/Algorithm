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

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  deque<int> dq;

  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  int card = 1;
  for (int i = N - 1; i >= 0; i--)
  {
    int t = A[i];

    if (t == 1)
    {
      dq.push_back(card);
    }
    else if (t == 2)
    {
      int a;
      a = dq.back();
      dq.pop_back();
      dq.push_back(card);
      dq.push_back(a);
    }
    else
    {
      dq.push_front(card);
    }
    card++;
  }

  for (int i = N - 1; i >= 0; i--)
  {
    cout << dq[i] << ' ';
  }

  return 0;
}
