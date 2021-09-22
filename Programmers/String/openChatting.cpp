#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

vector<string> split(string t){
    vector<string> res;
    int n= t.length();
    
    string temp="";
    for(int i=0;i<n;i++){
        if(t[i] ==' '){
            res.push_back(temp);
            temp ="";
        }
        else{
            temp+=t[i];
        }
    }
    res.push_back(temp);
    //cout<<t<<' ';
    return res;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string>m;
    queue <pair<string,bool>> q;
    
    string temp;
    for(string t: record){
        vector<string> x = split(t);
        
       if(x[0] =="Enter"){
           m[x[1]] = x[2];
           q.push({x[1],0});//들어오는걸 0
       }
       else if(x[0] == "Leave"){
           q.push({x[1],1});// 나가는걸 1
       }
       else if(x[0] == "Change"){
           m[x[1]] = x[2];
       }
    }
    
    while(!q.empty()){
        string id = m[q.front().first];
        bool inOut = q.front().second;
        
        string tempRes ="";
        if(inOut){
            tempRes +=id;
            tempRes+="님이 나갔습니다.";
        }
        else{
            tempRes +=id;
            tempRes +="님이 들어왔습니다.";
        }
        answer.push_back(tempRes);
        q.pop();
    }
   
    return answer;
}