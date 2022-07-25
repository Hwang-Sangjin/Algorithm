struct Node
{
  int cnt;
  int list[100];

  Node()
  {
    cnt = 0;
  }
  void clear()
  {
    cnt = 0;
  }
  void push_back(int n)
  {
    list[cnt++] = n;
  }
  int size()
  {
    return cnt;
  }
};

Node tree[100];

void dfs_init(int N, int path[100][2])
{
  for (int i = 0; i < 100; i++)
    tree[i].clear();

  for (int i = 0; i < N - 1; i++)
    tree[path[i][0]].push_back(path[i][1]);
}

void dfs_rec(int n, int idx, int &first)
{
  if (first != -1)
    return;
  if (n < idx)
  {
    first = idx;
    return;
  }

  for (int i = 0; i < tree[idx].size(); i++)
    dfs_rec(n, tree[idx].list[i], first);
}

int dfs(int n)
{
  int first = -1;
  dfs_rec(n, n, first);

  return first;
}