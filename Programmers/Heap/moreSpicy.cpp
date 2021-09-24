#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct cmp{
  bool operator()(int x, int y){
      if(x> y) return true;
      else return false;
  }  
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>, cmp > pq;
    
    for(int t: scoville){
        pq.push(t);
    }
    
    bool check = false;
    while(!pq.empty()){
        int first = pq.top();
        if(first >= K){
            check = true;
            break;
        }
        
        answer++;
        pq.pop();
        if(pq.empty()) break;
        int second = pq.top();
        pq.pop();
        
        int temp = second*2 + first;
        pq.push(temp);
        
    }
    if(check== false) answer =-1;
    
    return answer;
}