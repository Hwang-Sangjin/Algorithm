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

  int N, temp;
  cin >> N;

  vector<int> v;

  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  int res = 1;
  for (int i = 0; i < N; i++)
  {
    if (res < v[i])
    {
      break;
    }
    res += v[i];
  }
  cout << res;

  return 0;
}
