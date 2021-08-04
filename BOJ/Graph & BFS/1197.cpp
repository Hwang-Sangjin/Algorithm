#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int Parent[10001];

int findP(int index) {
    if (Parent[index] == index) return index;
    else return Parent[index] = findP(Parent[index]);
}
void Union(int x, int y)
{
    x = findP(x);
    y = findP(y);

    if (x != y) Parent[y] = x;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> v;

    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v.push_back({ C,{A,B} });
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= V; i++)
    {
        Parent[i] = i;
    }

    int res = 0;
    for (int i = 0; i < E; i++)
    {
        int x = v[i].second.first;
        int y = v[i].second.second;
        int cost = v[i].first;

        int Px = findP(x);
        int Py = findP(y);

        if (Px != Py ) {
            Parent[Py] = Px;
            res += cost;
        }
    }
    cout << res;


    return 0;
}
