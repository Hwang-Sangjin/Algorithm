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

  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int chickenN = min(X, Y);

  int answer = (A + B > C * 2) ? (C * 2 * chickenN) : ((A + B) * chickenN);
  answer += (X - chickenN) * ((A > C * 2) ? (C * 2) : (A));
  answer += (Y - chickenN) * ((B > C * 2) ? (C * 2) : (B));

  cout << answer;
  return 0;
}
