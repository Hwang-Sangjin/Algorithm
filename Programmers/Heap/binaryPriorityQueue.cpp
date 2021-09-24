#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <algorithm>

int v[1000002];

using namespace std;
struct mincmp{
  bool operator()(int x, int y){
      if(x>y) return true;
      else return false;
  }  
};
struct maxcmp{
  bool operator()(int x, int y){
      if(x< y) return true;
      else return false;
  }  
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int,vector<int>, mincmp> minPQ;
    priority_queue<int,vector<int>, maxcmp> maxPQ;

    int cnt =0;
    for(auto t: operations){
        if(cnt==0){
            while(!maxPQ.empty())maxPQ.pop();
            while(!minPQ.empty())minPQ.pop();
        }
        
        if(t[0]=='I'){
            string temp="";
            for(int i=2;i<t.length();i++){
                temp+=t[i];
            }
            
            int IntTemp = stoi(temp);
            minPQ.push(IntTemp);
            maxPQ.push(IntTemp);
            cnt++;
        }
        else{
            if(cnt==0) continue;
            if(t=="D 1"){
                maxPQ.pop();
                cnt--;
            }
            else{
                minPQ.pop();
                cnt--;
            }
        }
    }
    
    int minRes=0, maxRes =0;
    
    if(cnt>0){
        minRes = minPQ.top();
        maxRes = maxPQ.top();
    }
    
    
    answer.push_back(maxRes);
    answer.push_back(minRes);
    return answer;
}