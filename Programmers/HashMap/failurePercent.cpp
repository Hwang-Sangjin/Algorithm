#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<float, int> a, pair<float,int> b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,int>unclear;
    map<int,int>reach;

    for(int i=0;i<stages.size();i++){
        unclear[stages[i]]++;
        for(int j=1;j<=N;j++){
            if(j<= stages[i]){
                reach[j]++;
            }
        }
    }
    vector<pair<float, int>>res;
    float temp=0;
    for(int i=1;i<=N;i++){
        if(reach[i]==0) {
            temp=0;
        }
        else{
            temp = float(unclear[i])/reach[i];
        }
        res.push_back({temp,i});
    }
    sort(res.begin(),res.end(),cmp);
    
    for(auto t : res){
        answer.push_back(t.second);
    }
    
    
    return answer;
}