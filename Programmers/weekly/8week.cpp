#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<pair<int,int>> v;
    
    for(int i=0;i<sizes.size();i++){
        int x = sizes[i][0];
        int y= sizes[i][1];
        
        int z = min(x,y);
        if(z == x){
            v.push_back({x,y});
        }
        else{
            v.push_back({y,x});
        }
    }
    
    int w=0,h=0;
    for(auto t: v){
        if(t.first > w) w = t.first;
        if(t.second > h) h= t.second;
    }
    answer = w*h;
    return answer;
}