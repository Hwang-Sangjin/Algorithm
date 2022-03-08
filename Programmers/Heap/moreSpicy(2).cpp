#include <string>
#include <vector>
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
    
    priority_queue<int,vector<int>,cmp> pq;
    
    for(auto t: scoville){
        pq.push(t);
    }
    bool check = false;
    while(!pq.empty()){
        int f= pq.top();
        
        if(f >= K){
            check = true;
            break;
        }
        pq.pop();
        if(pq.empty()) break;
        
        int s = pq.top();
        pq.pop();
        
        int t = f+ s*2;
        pq.push(t);
        answer++;
    }
    if(!check)answer =-1;
    
    return answer;
}