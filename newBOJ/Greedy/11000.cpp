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

int N;
priority_queue<int,vector<int>, greater<int>>pq;
vector<pair<int,int>> class_time;

int greedy(){
    pq.push(class_time[0].second);

    for(int i=1;i<N;i++){
        pq.push(class_time[i].second);

        if(pq.top() <= class_time[i].first){
            pq.pop();
        }
    }
    return pq.size();

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    
    cin>>N;

    int s,f;
    for(int i=0;i<N;i++){
        cin>>s>>f;
        class_time.push_back({s,f});
    }

    sort(class_time.begin(), class_time.end());

    cout<< greedy();
    
    
    return 0;
}