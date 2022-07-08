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

class Node
{
public:
  int key;
  Node *left;
  Node *right;

  Node *insert(Node *node, int _key)
  {
    if (node == nullptr)
    {
      node = new Node;
      node->key = _key;
      node->left = nullptr;
      node->right = nullptr;
    }
    else if (node->key < _key)
    {
      node->right = insert(node->right, _key);
    }
    else
    {
      node->left = insert(node->left, _key);
    }
    return node;
  }
};

void postOrder(Node *node)
{
  if (node->left != nullptr)
  {
    postOrder(node->left);
  }
  if (node->right != nullptr)
  {
    postOrder(node->right);
  }
  cout << node->key << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *root = nullptr;
  int num = 0;

  while (cin >> num)
  {
    if (num == cin.eof())
      break;
    root = root->insert(root, num);
  }
  postOrder(root);

  return 0;
}
