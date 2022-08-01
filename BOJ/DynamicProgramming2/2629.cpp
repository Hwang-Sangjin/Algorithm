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

int n,bead, x, weight[31];
bool dp[31][15002];

void DFS(int i, int w){
    if(i>n || dp[i][w]) return;
    dp[i][w] = true;
    DFS(i+1,w);
    DFS(i+1,w+weight[i]);
    DFS(i+1,abs(w-weight[i]));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    DFS(0,0);

    cin>>bead;

    for(int i=0;i<bead;i++){
        cin>>x;
        if(x>15000 || dp[n][x]==false) cout<<"N ";
        else cout<<"Y ";
    }
  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}