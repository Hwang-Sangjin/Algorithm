#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n= progresses.size();
    
    queue<int> q;
    
    for(int i=0;i<n;i++){
        int t= 100-progresses[i];
        if(t%speeds[i]==0){
            q.push(t/speeds[i]);
        }
        else{
            q.push(t/speeds[i] + 1);
        }
    }
    
    int day=0;
    int cnt=0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(day < t){
            day = t;
            if(cnt!=0){
                answer.push_back(cnt);
            }
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    answer.push_back(cnt);
    
    
    return answer;
}