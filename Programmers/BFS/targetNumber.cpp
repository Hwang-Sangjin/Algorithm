#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int N = numbers.size();
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int tres = t.first;
        int tcnt = t.second;
        
        if(tcnt == N){
            if(tres == target){
                answer++;
            }
            else{
                continue;
            }
        }
        else{
            q.push({tres+numbers[tcnt],tcnt+1});
            q.push({tres-numbers[tcnt],tcnt+1});
        }
        
    }
    
    return answer;
}