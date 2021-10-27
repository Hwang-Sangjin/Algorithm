#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> v;
    for(int i=0;i<dungeons.size();i++){
        v.push_back(i);
    }
    
    do{
        int cnt=0;
        int rest = k;
        for(auto t: v){
            if(rest >= dungeons[t][0]){
                rest -= dungeons[t][1];
                cnt++;
            }
            else break;
        }
        
        answer = max(answer,cnt);
    }while(next_permutation(v.begin(),v.end()));
    
    return answer;
}