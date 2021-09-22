#include <vector>
#include <queue>
#include <string.h>

using namespace std;
bool v[102][102];

int bfs(int i, int j,vector<vector<int>> P,int M,int N){
    int di[4] = {-1,0,1,0};
    int dj[4] = {0,1,0,-1};
    int cnt=0;
    int index = P[i][j];
    queue<pair<int,int>>q;
    q.push({i,j});
    v[i][j] = true;
    
    while(!q.empty()){
        int ti = q.front().first;
        int tj = q.front().second;
        q.pop();
        cnt++;
        
        for(int k=0;k<4;k++){
            int ni = ti + di[k];
            int nj = tj + dj[k];
            if(ni<0 || nj<0 || ni>=M || nj>=N || v[ni][nj] || P[ni][nj] != index) continue;
            q.push({ni,nj});
            v[ni][nj] = true;
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    memset(v,false, sizeof(v));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]==0) continue;
            if(v[i][j] == false){
                number_of_area++;
                int temp = bfs(i,j,picture,m,n);
                max_size_of_one_area = max(max_size_of_one_area, temp);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}