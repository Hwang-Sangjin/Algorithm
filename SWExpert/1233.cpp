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

struct Node
{
  char alpha;
  int left;
  int right;
};

vector<Node> tree(102);

void Inorder(int index)
{
  if (tree[index].left != 0)
    Inorder(tree[index].left);
  cout << tree[index].alpha;
  if (tree[index].right != 0)
    Inorder(tree[index].right);
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int T = 1; T <= 1; T++)
  {
    tree.clear();
    tree.resize(102);
    int N;
    cin >> N;

    int index;
    char alpha;
    for (int i = 1; i <= N; i++)
    {
      int left = 0, right = 0;
      cin >> index >> alpha;

      if (cin.get() != '\n')
      {
        cin >> left;
        if (cin.get() != '\n')
        {
          cin >> right;
        }
      }
      tree[index].alpha = alpha;
      tree[index].left = left;
      tree[index].right = right;
    }

    cout << '#' << T << ' ';
    Inorder(1);
    cout << '\n';
  }

  return 0;
}
