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

struct box
{
  int str;
  int fin;
  int boxCnt;
};

vector<box> v;
int town[2001];

bool cmp(box l, box r)
{
  if (l.fin == r.fin)
  {
    return l.str < r.str;
  }
  return l.fin < r.fin;
}

int N, C, M;
int res = 0;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> C >> M;

  for (int i = 0; i < M; i++)
  {
    int str, fin, boxCnt;
    cin >> str >> fin >> boxCnt;
    v.push_back({str, fin, boxCnt});
  }
  memset(town, 0, sizeof(town));

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < M; i++)
  {
    int str = v[i].str;
    int fin = v[i].fin;
    int ableBox = v[i].boxCnt;

    for (int j = str; j < fin; j++)
    {
      if (C - town[j] <= ableBox)
      {
        ableBox = C - town[j];
      }
    }

    for (int j = str; j < fin; j++)
    {
      town[j] += ableBox;
    }

    res += ableBox;
  }

  cout << res;

  return 0;
}
