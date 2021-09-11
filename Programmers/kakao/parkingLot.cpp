#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

pair<int,int> car[10000];
bool carIn[10000];
bool carCheck[10000];
int carTime[10000];
vector<int> carN;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int n = records.size();
    
    for(int i=0;i<n;i++){
        int hour = stoi(records[i].substr(0,2));
        int min = stoi(records[i].substr(3,5));

        int carNum = stoi(records[i].substr(6,10));
        string condition = records[i].substr(11);
        if(carCheck[carNum] == false){
            carN.push_back(carNum);
            carCheck[carNum] = true;
        }
        //cout<<hour<<' '<<min<<' '<<carNum<<' '<<condition<<'\n';
        if(condition == "IN"){
            car[carNum] = {hour,min};
            carIn[carNum] = true;
        }
        else{
            auto t= car[carNum];            
            int thour = t.first;
            int tmin = t.second;
            //cout<<hour<<' '<<min<<' '<<carNum<<' '<<condition<<'\n';
            //cout<<thour<<' '<<tmin<<'\n';
            int InTime = thour*60 + tmin;
            int OutTime = hour*60 + min;
            int totalTime = OutTime - InTime;
            carTime[carNum] += totalTime;
            //cout<<totalTime<<'\n';
            carIn[carNum] = false;
        }
    }
    sort(carN.begin(),carN.end());
    for(auto t: carN){
        if(carIn[t]){
            auto temp= car[t];            
            int thour = temp.first;
            int tmin = temp.second;
            //cout<<hour<<' '<<min<<' '<<carNum<<' '<<condition<<'\n';
            //cout<<thour<<' '<<tmin<<'\n'; 
            int InTime = thour*60 + tmin;
            int OutTime = 23*60 + 59;
            int totalTime = OutTime - InTime;
            carTime[t] += totalTime;
            //cout<<totalTime<<'\n';
            carIn[t] = false;
        }
        //cout<<carTime[t]<<'\n';
    }
    
    int normalMin = fees[0];
    int normalFee = fees[1];
    int PerMin = fees[2];
    int normalFeePerMin = fees[3];
    
    for(auto t: carN){
        if(carTime[t]<=normalMin){
            answer.push_back(normalFee);
        }
        else{
            int res =normalFee;
            float k = (carTime[t]-normalMin)/float(PerMin);
            int upK = ceil(k) * normalFeePerMin;
            res +=upK;
            //cout<<k<<' '<<upK<<'\n';
            answer.push_back(res);
        }
    }
    
    return answer;
}