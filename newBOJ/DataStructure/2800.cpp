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
vector<pair<int, int>> Gwalho;
set<string> answer;
string S;
bool Select[202];
bool Visit[10];

void input()
{

  cin >> S;

  stack<int> st;

  for (int i = 0; i < S.length(); i++)
  {
    if (S[i] == '(')
      st.push(i);
    else if (S[i] == ')')
    {
      Gwalho.push_back({st.top(), i});
      st.pop();
    }
  }
}

void Recursive(int index, int cnt)
{
  if (cnt >= 1)
  {
    string T = "";

    for (int i = 0; i < S.length(); i++)
    {
      if (Select[i])
        continue;
      T += S[i];
    }
    if (!answer.count(T))
    {
      answer.insert(T);
    }
  }

  for (int i = index; i < Gwalho.size(); i++)
  {
    if (Visit[i])
      continue;

    Visit[i] = true;
    Select[Gwalho[i].first] = true;
    Select[Gwalho[i].second] = true;

    Recursive(i + 1, cnt + 1);

    Visit[i] = false;
    Select[Gwalho[i].first] = false;
    Select[Gwalho[i].second] = false;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  Recursive(0, 0);

  for (auto t : answer)
  {
    cout << t << '\n';
  }

  return 0;
}
