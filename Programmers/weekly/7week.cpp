#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool v[1002][1002];
bool out[1002];
bool meetingRoom[1002];

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    
    int n= enter.size();
    int enterIndex =0;
    
    for(int i=0;i<n;i++){
        int nextLeave = leave[i];
        
        for(int k=1;k<=n;k++){
            if(meetingRoom[k] == true){
                v[nextLeave][k] = true;
                v[k][nextLeave] = true;
            }
        }
        
       // cout<<nextLeave<<": ";
        
        if(meetingRoom[nextLeave]== true){
            meetingRoom[nextLeave] = false;
        }
        else{
            for(;enterIndex<n;enterIndex++){
                int enteringOne = enter[enterIndex];
                //cout<<enteringOne<<' ';
                if(enteringOne == nextLeave){
                    break;
                }
                else{
                    if(out[enteringOne]) continue;
                    v[nextLeave][enteringOne] = true;
                    for(int k=1;k<=n;k++){
                        if(meetingRoom[k]){
                            v[enteringOne][k] = true;
                            v[k][enteringOne] = true;
                        }
                    }
                    v[enteringOne][nextLeave] = true;
                    meetingRoom[enteringOne] = true;
                }
            }
        }
        //cout<<'\n';
        out[nextLeave] = true;
        v[nextLeave][nextLeave] = false;
    }
        //cout<<'\n';
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<v[i][j];
    //     }
    //     cout<<'\n';
    // }
    
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(v[i][j])cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}