#include <iostream>
#include <vector>
#include <queue>
#define MAX 500000;
using namespace std;


int map[51][51];
int dp[51];
int n;

void djikstra(){
    priority_queue<pair<int,int>> q;
    q.push({0,1});
    dp[1] =0;
    
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int tcost = t.first;
        int ti = t.second;
        //cout<<ti<<' '<<tcost<<'\n';
        
        for(int i=1;i<=n;i++){
            if(map[ti][i]==0) continue;
            if(dp[i] <= tcost + map[ti][i]) continue;
            q.push({tcost+map[ti][i],i});
            dp[i] = tcost + map[ti][i];
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    n=N;
    
    for(auto t: road){
        int a = t[0];
        int b = t[1];
        int cost = t[2];
        if(map[a][b] == 0){
            map[a][b] = cost;
            map[b][a] = cost;
        }
        else{
            if(map[a][b] > cost){
                map[a][b] = cost;
                map[b][a] = cost;
            }
        }
        
    }
    
    for(int i=1;i<=N;i++){
        dp[i] = MAX;
    }
    
    djikstra();
    
    for(int i=1;i<=N;i++){
       // cout<<dp[i]<<'\n';
        if(dp[i] <=K){
          
            answer++;
        } 
    }
    
    return answer;
}