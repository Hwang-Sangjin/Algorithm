#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char o[3] = {'+', '-', '*'};

long long solution(string expression) {
    
    
    long long answer = 0;
    
    vector<long long> operand;
    vector<char> oper;
    
    string temp="";
    for(int i=0;i<expression.length();i++){
        if(expression[i]==o[0] || expression[i]==o[1] ||expression[i]==o[2]){
            operand.push_back(stoi(temp));
            temp ="";
            oper.push_back(expression[i]);
        }
        else{
            temp+=expression[i];
        }
    }
    operand.push_back(stoi(temp));
    
    vector<int> p;
    for(int i=0;i<3;i++){
        p.push_back(i);
    }
    
    do{
        vector<long long> toperand = operand;
        vector<char> toper = oper;
        
        for(auto t: p){
            cout<<o[t]<<' ';
        }
        cout<<'\n';
        for(auto t: p){
            //cout<<t<<' ';
            for(int i=0;i<toper.size();i++){
                long long temp =0;
                if(toper[i] == o[t]){
                    if(o[t]=='+'){
                        temp = toperand[i]+toperand[i+1];
                        //cout<<temp<<' ';
                        toperand.erase(toperand.begin()+i+1);
                        toperand[i] = temp;
                        toper.erase(toper.begin()+i);
                        temp =0;
                        i=-1;
                    }
                    else if(o[t]== '-'){
                        temp = toperand[i]-toperand[i+1];
                        //cout<<temp<<' ';
                        toperand.erase(toperand.begin()+i+1);
                        toperand[i] = temp;
                        toper.erase(toper.begin()+i);
                        temp =0;
                        i=-1;
                    }
                    else if(o[t]=='*'){
                        temp = toperand[i]*toperand[i+1];
                        //cout<<temp<<' ';
                        toperand.erase(toperand.begin()+i+1);
                        toperand[i] = temp;
                        toper.erase(toper.begin()+i);
                        temp =0;
                        i=-1;
                    }
                }
            }
        }
        cout<<abs(toperand[0])<<'\n';
        if(answer < abs(toperand[0])) answer = abs(toperand[0]);
        
    }while(next_permutation(p.begin(),p.end()));
    
    return answer;
}