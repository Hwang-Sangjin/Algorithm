#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;
bool map[102][102];
bool visited[102];

int bfs(int index, int n){
    queue<int>q;
    q.push(index);
    visited[index] = true;
    int cnt=0;
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cnt++;
        
        for(int k=1;k<=n;k++){
            if(visited[k]== true) continue;
            if (map[t][k] == true) {
                q.push(k);
                visited[k] = true;
            }
        }
    }
    return cnt;
}

int cut(int x, int y,int n){
    map[x][y] = false;
    map[y][x] = false;
    
    memset(visited,false, sizeof(visited));
    
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(visited[i]== true) continue;
        res.push_back(bfs(i,n));
    }
    int r = abs(res[0]-res[1]);
    
    map[x][y] = true;
    map[y][x] = true;
    
    return r;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    for(auto t: wires){
        int x = t[0];
        int y = t[1];
        map[x][y] = true;
        map[y][x] = true;
    }
    for(auto t: wires){
        int x = t[0];
        int y = t[1];
        int res = cut(x,y,n);
        
        if(answer == -1) answer = res;
        else{
            answer = min(answer,res);
        }
    }
    
    return answer;
}