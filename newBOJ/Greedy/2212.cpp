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

  int N, K;
  cin >> N >> K;

  vector<int> station(N);

  for (int i = 0; i < N; i++)
  {
    cin >> station[i];
  }

  sort(station.begin(), station.end());

  vector<int> dis(N - 1);

  for (int i = 0; i < N - 1; i++)
  {
    dis[i] = station[i + 1] - station[i];
  }

  sort(dis.begin(), dis.end());

  int res = 0;
  for (int i = 0; i < N - K; i++)
  {
    res += dis[i];
  }
  cout << res;

  return 0;
}
