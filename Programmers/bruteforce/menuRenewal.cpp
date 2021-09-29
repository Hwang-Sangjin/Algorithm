#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    map<string, int> m;
    sort(orders.begin(),orders.end());
    
    for(int cnt : course){
        set<string> res;
        for(string s: orders){
            if(cnt > s.length()) continue;
            vector<int> v(s.length()-cnt,0);
            for(int i=0;i<cnt;i++){
                v.push_back(1);
            }
            
            do{
                string temp="";
                for(int i=0;i<s.length();i++){
                    if(v[i]==1){
                        temp+=s[i];
                    }
                }
                sort(temp.begin(),temp.end());
                m[temp]++;
                res.insert(temp);
            }while(next_permutation(v.begin(),v.end()));
        }
        
        vector<pair<string,int>> v;
        for(auto t: res){
            v.push_back({t,m[t]});
        }
        sort(v.begin(),v.end(),cmp);
        
        int max =v[0].second;
        for(auto t: v){
            cout<<t.first<<' '<<t.second<<'\n';
        }
        
        for(auto t: v){
            if(max == t.second){
                if(max!=1){
                    answer.push_back(t.first);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}