#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    //큐, 시뮬레이션
    queue <int>q ;
    for(int i=0;i<bridge_length;i++){
        q.push(0);
    }
    
    int entered_truck_cnt =0;
    int bridge_weight =0;
    
    while(!q.empty()){
        answer++;
        
        bridge_weight-=q.front();
        q.pop();
        
        if(entered_truck_cnt < truck_weights.size()){
            if(weight >= bridge_weight+ truck_weights[entered_truck_cnt]){
                q.push(truck_weights[entered_truck_cnt]);
                bridge_weight+=truck_weights[entered_truck_cnt];
                entered_truck_cnt++;
            }
            else{
                q.push(0);
            }
        }
    }
    return answer;
}