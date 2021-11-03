#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

using namespace std;
int v[305][305];
vector<vector<int>> Land;
vector<pair<int,pair<int,int>>> edge;
vector<int> parent;
int H,N;
int cnt=1;
int answer;

void BFS(int x, int y,int team){
    queue<pair<int,int>> q;
    q.push({x,y});
    v[x][y] = team;
    
    while(!q.empty()){
        auto t= q.front();
        int ti = t.first;
        int tj = t.second;
        //cout<<ti<<' '<<tj<<'\n';
        q.pop();
        
        for(int k=0;k<4;k++){
            int ni = ti + di[k];
            int nj = tj + dj[k];
            
            if(ni>=0 && nj>=0&& ni<N && nj<N){
                int temp = abs(Land[ti][tj] - Land[ni][nj]);
                if(temp <=H && v[ni][nj]== 0){
                    v[ni][nj] = team;
                    q.push({ni,nj});
                }
            }
        }
    }
}


void make_group(){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(v[i][j]==0){
                BFS(i,j,cnt++);
            }
        }
    }
    
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<v[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
}

void Distance(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                int ni = i + di[k];
                int nj = j + dj[k];
                
                if(ni>=0 && nj>=0&& ni<N && nj<N){
                    
                    if(v[i][j] != v[ni][nj]){
                        edge.push_back({abs(Land[i][j] - Land[ni][nj]),{v[i][j],v[ni][nj]}});
                    }
                }
            }
        }
    }
}

int Parent(int x){
    if(x == parent[x]) return x;
    else{
        return parent[x] = Parent(parent[x]);
    }
}

void Union(int x, int y){
    x = Parent(x);
    y = Parent(y);
    parent[y] = x;
}

bool Same_Parent(int x, int y){
    x = Parent(x);
    y = Parent(y);
    if(x== y) return true;
    return false;
}


void Kruskal(){
    parent.resize(cnt);
    for (int i = 1; i < cnt; i++) parent[i] = i;
    sort(edge.begin(),edge.end());
    
    for(int i=0;i<edge.size();i++){
        int ti = edge[i].second.first;
        int ni = edge[i].second.second;
        int cost = edge[i].first;
        //cout<<ti<<' '<<ni<<' '<<cost<<'\n';
        
        if(Same_Parent(ti,ni) == false){
            Union(ti,ni);
            answer+=cost;
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    Land = land;
    H = height;
    N = land.size();
    
    make_group();
    Distance();
    Kruskal();
    
    return answer;
}