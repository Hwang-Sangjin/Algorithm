#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

char kakaoF[8] = {'A','C','F','J','M','N','R','T'};

int index(int k){
    for(int i=0;i<8;i++){
        if(k == kakaoF[i]) return i;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    vector<int> v;
    for(int i=0;i<8;i++){
        v.push_back(i);
    }
    
    cout<<data[0][4];
    
    do{
        bool check = true;
        
        for(int i=0;i<n;i++){
            string d = data[i];
            int x = index(d[0]);
            int y = index(d[2]);
            int r = d[4]-47;
            char oper = d[3];
            
            int xi,yi;
            bool fx = false,fy=false;
            for(int j=0;j<8;j++){
                if(fx== false && x==v[j]){
                    xi = j;
                    fx = true;
                }
                if(fy == false && y==v[j]){
                    yi=j;
                    fy = true;
                }
            }
            int disxy = abs(xi-yi);
            
            if(oper == '='){
                if(disxy == r) continue;
                else{
                    check = false;
                    break;
                } 
            }
            else if(oper=='>'){
                if(disxy > r) continue;
                else{
                    check = false;
                    break;
                }
            }
            else if(oper=='<'){
                if(disxy < r) continue;
                else{
                    check = false;
                    break;
                }
            }
        }
        if(check) answer++;
        
    }while(next_permutation(v.begin(),v.end()));
    
    return answer;
}