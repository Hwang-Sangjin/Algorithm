#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1]> b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, j=0, time=0;
    
    sort(jobs.begin(),jobs.end());
    
    priority_queue <vector<int>, vector<vector<int>>, cmp> pq;
    
    while(j< jobs.size() || !pq.empty()){
        cout<<"시간"<<time<<'\n';
        if(jobs.size()> j && time>= jobs[j][0]){
            cout<<jobs[j][0]<<' '<<jobs[j][1]<<'\n';
            pq.push(jobs[j++]);
            continue;
        }
        if(!pq.empty()){
            time+=pq.top()[1];
            answer+=time-pq.top()[0];
            pq.pop();
        }
        else time = jobs[j][0];
        cout<<"정답"<<time<<' '<<answer<<'\n';
    }
    
    return answer/ jobs.size();
}