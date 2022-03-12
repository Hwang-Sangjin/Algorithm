#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int dp[1000002];
int coin[6] = {1,5,10,50,100,500};

int solution(int money, vector<int> costs) {
    int answer = 0;
    //memset(dp,sizeof(dp),-1);

    for(int i=1;i<=4;i++){
        dp[i] = costs[0] * i;
    }

    for(int i=5;i<=money;i++){
        for(int j=0;j<6;j++){
            int t = i-coin[j];
            if(t>0){
                if(dp[i]==0 || dp[i] > dp[t] + costs[j]){
                    dp[i] = dp[t] + costs[j];
                }
            }
        }
    }
    answer = dp[money];

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};
bool v[1002][1002];

vector<vector<int>> bfs(int n, vector <vector<int>> map, bool clockwise){
    queue<pair<pair<int,int>,pair<int,int>>> q;
    if(clockwise){
        q.push({{0,0},{1,1}});
        q.push({{n-1,0},{1,0}});
        q.push({{0,n-1},{1,2}});
        q.push({{n-1,n-1},{1,3}});
    }
    else{
        q.push({{0,0},{1,2}});
        q.push({{n-1,0},{1,1}});
        q.push({{0,n-1},{1,3}});
        q.push({{n-1,n-1},{1,0}});
    }
    
    map[0][0] = 1;
    map[n-1][0] = 1;
    map[0][n-1] = 1;
    map[n-1][n-1] = 1;
    v[0][0] = true;
    v[n-1][0] = true;
    v[0][n-1] = true;
    v[n-1][n-1] = true;

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        auto tpos = t.first;
        auto tcon = t.second;
        int ti = tpos.first;
        int tj = tpos.second;
        int tcnt = tcon.first;
        int tdir = tcon.second;
        
        int ni = ti + di[tdir];
        int nj = tj + dj[tdir];

        if(v[ni][nj]){
            int ndir;
            if(clockwise){
                ndir = (tdir + 1)%4;
            }
            else{
                ndir = (tdir + 3) %4;
            }
            ni = ti + di[ndir];
            nj = tj + dj[ndir];
            if(v[ni][nj]) continue;

            q.push({{ni,nj},{tcnt+1,ndir}});
            map[ni][nj] = tcnt+1;
            v[ni][nj] = true;
        }
        else{
            q.push({{ni,nj},{tcnt+1,tdir}});
            map[ni][nj] = tcnt+1;
            v[ni][nj] = true;
        }
    }

    return map;
}

vector<vector<int>> solution(int n, bool clockwise) {
    vector<vector<int>> answer;
    vector <vector<int>> map(n,vector<int>(n,0));

    answer = bfs(n,map, clockwise);

    return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int width, int height, vector<vector<int>> diagonals) {
    int answer = 0;

    for(int index =0;index<diagonals.size();index++){
        vector<vector<int>>map(height+2,vector<int>(width+2,0));
        int di = diagonals[index][1];
        int dj = diagonals[index][0];

        for(int i=0;i<=di;i++){
            map[i][0] = 1;
        }
        for(int j=0;j<=dj;j++){
            map[0][j] = 1;
        }

        for(int i=1;i<=di;i++){
            for(int j=1;j<=dj;j++){
                map[i][j] = (map[i-1][j] + map[i][j-1])%10000019;
            }
        }

        int temp = map[di][dj-1];
        map[di][dj-1] = map[di-1][dj];
        map[di-1][dj] = temp;
        //di =2 dj =1
        for(int i=di;i<=height;i++){
            map[i][dj-1] = map[di][dj-1];
        }
        
        for(int j=dj;j<=height;j++){
            map[di-1][j] = map[di-1][dj];
        }

        for(int i=0;i<=height;i++){
            for(int j=0;j<=width;j++){
                cout<<map[i][j]<<"  ";
            }
            cout<<'\n';
        }

        for(int i=di;i<=height;i++){
            for(int j=dj;j<=width;j++){
                map[i][j] = (map[i-1][j] + map[i][j-1])%10000019;
            }
        }
        answer = (answer + map[height][width])%10000019;
    }

    return answer;
}