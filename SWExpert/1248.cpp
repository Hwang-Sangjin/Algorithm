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

using namespace std;

struct Node{
    int num;
    vector<int> children;
    int parent;
};

int V,E;

vector<Node> tree(10002);
bool visited[10002];

int BFS(int x, int y){
    queue<int> q;
    q.push(x);
    q.push(y);

    while(!q.empty()){
        int t= q.front();
        q.pop();
		if(t==1) continue;
        if(visited[tree[t].parent]) return tree[t].parent;

        q.push(tree[t].parent);
        visited[tree[t].parent] = true;
    }
}

int CntTree(int root){
    queue<int> q;
    q.push(root);
    int cnt=0;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        cnt++;

        for(int k: tree[t].children){
            q.push(k);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int test_case;
	int T=10;
    cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(visited,false,sizeof(visited));
        tree.clear();
        
		int x,y;
        cin>>V>>E>>x>>y;
        tree.resize(V+1);
        int c,p;

        for(int i=0;i<E;i++){
        	cin>>p>>c;
            tree[p].children.push_back(c);
            tree[c].parent = p;
        }

        int res = BFS(x,y);
        int TreeSize = CntTree(res);

        cout<<'#'<<test_case<<' '<<res<<' '<<TreeSize<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}