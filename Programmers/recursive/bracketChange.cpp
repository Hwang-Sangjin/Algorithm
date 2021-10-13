#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(string p){
    int t=0;
    for(int i=0;i<p.length();i++){
        //cout<<p[i];
        if(p[i]=='(') t++;
        else{
            if(t==0) return false;
            t--;
        }
    }
    return true;
}

string recursive(string p){
    if(p=="")return p;
    
    int LCnt=0,RCnt=0;
    string u="",v="";
    
    for(int i=0;i<p.length();i++){
        if(p[i]=='(') LCnt++;
        else RCnt++;
        
        if(LCnt == RCnt){
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(check(u)) return u+ recursive(v);
    else{
        string temp ="(";
        temp+=recursive(v)+")";
        u = u.substr(1,u.length()-2);
        for(int i=0;i<u.length();i++){
            if(u[i]=='(')   temp+=')';
            else temp+='(';
        }
        return temp;
    }
}

string solution(string p) {
    string answer = "";
    if(check(p)){
        answer = p;
    }
    else{
        answer = recursive(p);
    }
    return answer;
}