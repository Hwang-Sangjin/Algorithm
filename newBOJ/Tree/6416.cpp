#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define INF 987654321
#define MAX 1000000 + 1
using namespace std;

// 6416 - 트리인가?

int find_root(unordered_set<int> &vertex, unordered_map<int, vector<int>> &edge)
{
  // root 노드란 들어오는 간선이 하나도 없는 노드이므로
  // vertex set에 해당 값이 존재하지 않으면 root 노드이다.
  int root = 0, cnt = 0;
  for (auto iter = edge.begin(); iter != edge.end(); iter++)
  {
    if (vertex.count(iter->first) == 0)
    {
      root = iter->first;
      cnt++;
      if (cnt >= 2)
      {
        return -1; // root가 여러 개 존재
      }
    }
  }
  return root;
}

bool BFS(unordered_map<int, vector<int>> &edge, unordered_map<int, int> &isVisited, int root)
{
  queue<int> q;
  q.push(root);
  isVisited[root] = 1;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < edge[cur].size(); i++)
    {
      int next = edge[cur][i];
      if (isVisited[next] == 0)
      { // 아직 방문한 곳이 아닌 경우
        isVisited[next] = 1;
        q.push(next);
      }
      else
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testcase = 0;

  while (true)
  {
    unordered_map<int, vector<int>> edge;
    unordered_map<int, int> isVisited; // key: node, second: isVisited(0:no, 1:yes)
    unordered_set<int> vertex;
    int u = 1, v = 1;
    bool isTree = false;
    testcase++;

    while (true)
    {
      cin >> u >> v;
      if (u == -1 && v == -1)
        return 0;
      if (u == 0 && v == 0)
        break;

      edge[u].emplace_back(v); // u -> v 간선
      vertex.insert(v);        // 들어오는 간선이 있는 정점 체크
      if (isVisited.count(u) == 0)
        isVisited[u] = 0;
      if (isVisited.count(v) == 0)
        isVisited[v] = 0;
    }

    int root = find_root(vertex, edge); // root 노드를 찾는다.
    if (root == -1)
    {
      cout << "Case " << testcase << " is not a tree." << '\n';
      continue;
    }
    else
    {
      if (BFS(edge, isVisited, root))
        isTree = true;
    }

    // 방문하지 않은 노드가 있는지 확인
    for (auto iter = isVisited.begin(); iter != isVisited.end(); iter++)
    {
      if (iter->second == 0)
      { // 방문하지 않은 노드가 있다면 조건 충족 X
        isTree = false;
        break;
      }
    }

    if (isTree)
    {
      cout << "Case " << testcase << " is a tree." << '\n';
    }
    else
    {
      cout << "Case " << testcase << " is not a tree." << '\n';
    }
  }
}
