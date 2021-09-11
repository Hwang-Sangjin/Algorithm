#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool r[1002][1002];
bool sus[1002];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    int n = id_list.size();
    
    vector<string> v;
    for(int i=0;i<n;i++){
        v.push_back(id_list[i]);
    }
    
    for(int i=0;i<report.size();i++){
        int sSize = report[i].length();
        
        int spaceI = report[i].find(' ');
        string x = report[i].substr(0,spaceI);
        string y = report[i].substr(spaceI+1,sSize);
        //cout<<x<<' '<<y<<'\n';
        
        bool fx = false;
        bool fy = false;
        int rx,ry;
        for(int k=0;k<n;k++){
            if(x==v[k]){
                rx = k;
                fx = true;
            }
            if(y==v[k]){
                ry = k;
                fy = true;
            }
            if(fx && fy) break;
        }
        
        r[rx][ry] = true;
    }
    
    for(int j=0;j<n;j++){
        int cnt =0;
        for(int i=0;i<n;i++){
            if(r[i][j])cnt++;
        }
        
        if(cnt>=k) sus[j] = true;
    }
    
    for(int i=0;i<n;i++){
        int cnt=0;
        
        for(int j=0;j<n;j++){
            if(sus[j] && r[i][j]) cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}