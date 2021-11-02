#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int di[4]={-1,0,1,0};
int dj[4] = {0,1,0,-1};

int xi[8]={-1,-1,0,1,1,1,0,-1};
int xj[8] = {0,1,1,1,0,-1,-1,-1};

int map[102][102];
bool v[102][102];

void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    v[0][0]=true;
    
    while(!q.empty()){
        auto t= q.front();
        int ti = t.first;
        int tj = t.second;
        map[ti][tj]=0;
        q.pop();
        
        for(int k=0;k<4;k++){
            int ni = ti + di[k];
            int nj = tj + dj[k];
            
            if(ni<0 || nj<0 || ni>102 || nj> 102|| v[ni][nj] || map[ni][nj]!=-1) continue;
            q.push({ni,nj});
            v[ni][nj] = true;
        }
    }
}

int getBFS(int cx,int cy,int ix,int iy){
    memset(v,false,sizeof(v));
    queue<pair<pair<int,int>,int>>q;
    q.push({{cy*2,cx*2},0});
    v[cy*2][cx*2]=true;
    ix*=2;
    iy*=2;
    //cout<<iy<<' '<<ix<<'\n';
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        auto tpos = t.first;
        int tcnt = t.second;
        int ti = tpos.first;
        int tj = tpos.second;
        //cout<<ti<<' '<<tj<<'\n';
        
        if(ti == iy && tj == ix){
            return tcnt/2;
        }
        
        for(int k=0;k<4;k++){
            int ni = ti + di[k];
            int nj = tj + dj[k];
            if(ni<0 || nj<0 || ni>102 || nj>102 || map[ni][nj]!=2 || v[ni][nj]) continue;
            
            q.push({{ni,nj},tcnt+1});
            v[ni][nj] = true;
        }
    }
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    memset(map,-1,sizeof(map));
    for(int i=0;i<rectangle.size();i++){
        int si = rectangle[i][0] *2;
        int sj = rectangle[i][1] *2;
        int ei = rectangle[i][2] *2;
        int ej = rectangle[i][3] *2;
        
        for(int y = sj;y<=ej;y++){
            for(int x = si;x<=ei;x++){
                map[y][x] = 1;
                
            }
        }        
    }
    
    bfs();
    
    for(int i=0;i<=102; i++){
        for(int j=0;j<=102;j++){
            if(map[i][j] == -1) map[i][j] = 1;
        }
    }
    
    for(int i=0;i<=102; i++){
        for(int j=0;j<=102;j++){
            bool border = false;
            for(int k=0;k<8;k++){
                if(map[i+xi[k]][j+xj[k]] == 0 && map[i][j] ==1){
                    border = true;
                    break;
                }
            }
            if(border){
                map[i][j] = 2;
            }
        }
    }
    
    

    answer = getBFS(characterX,characterY,itemX,itemY);
    
    return answer;
}