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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<int> crain(N);

  for (int i = 0; i < N; i++)
  {
    cin >> crain[i];
  }

  int M;
  cin >> M;

  vector<int> box(M);
  for (int i = 0; i < M; i++)
  {
    cin >> box[i];
  }

  sort(crain.begin(), crain.end());
  sort(box.begin(), box.end());

  int cnt = 0;

  if (crain.back() < box.back())
  {
    cout << -1;
    return 0;
  }
  while (!box.empty())
  {
    cnt++;
    for (int i = crain.size() - 1; i >= 0; i--)
    {
      for (int j = box.size() - 1; j >= 0; j--)
      {
        if (crain[i] >= box[j])
        {
          box.erase(box.begin() + j);
          break;
        }
      }
    }
  }
  cout << cnt;

  return 0;
}
