#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int index;
    int weight;
    double winRatio;
    int HeavierWinCnt;
} Boxer;

bool cmp(Boxer a, Boxer b){
    if(a.winRatio > b.winRatio){
        return true;
    }
    
    if(a.winRatio == b.winRatio){
        if(a.HeavierWinCnt > b.HeavierWinCnt){
            return true;
        }
        
        else if(a.HeavierWinCnt == b.HeavierWinCnt){
            if(a.weight > b.weight){
                return true;
            }
            else if(a.weight== b.weight){
                if(a.index < b.index){
                    return true;
                }
            }
        }
    }
    return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    
    //승률, heavierWin 횟수, 몸무게, index
    vector<Boxer> boxers;
    
    for(int i=0;i<head2head.size();i++){
        double wins =0;
        double total =0;
        int HeavierWinCnt=0;
        
        for(int j=0;j<head2head[i].size();j++){
            if(head2head[i][j] == 'N') continue;
            
            total++;
            if(head2head[i][j] == 'W'){
                wins++;
                if(weights[i]< weights[j]){
                    HeavierWinCnt ++;
                }
            }
        }
        double winRate;
        //cout<<wins<<' '<<total<<'\n';
        
        if(total == 0){
            winRate =0;
        }
        else{
            winRate = wins/total;
        }
        
        boxers.push_back({i+1,weights[i], winRate, HeavierWinCnt});
    }
    
    sort(boxers.begin(),boxers.end(), cmp);
    
    for(auto t: boxers){
        answer.push_back(t.index);
    }
    
    return answer;
}