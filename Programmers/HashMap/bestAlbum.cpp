#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

map<string, int> m;
map<string, vector<pair<int,int>>>n;
set<string> genre;

bool cmp(pair<int,int> a, pair<int,int>b){
    if(a.first > b.first) return true;
    else if(a.first == b.first){
        if(a.second < b.second) return true;
    }
    return false;
}

bool upper(pair<string, int>a, pair<string, int>b){
    if(a.second > b.second) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++){
        //cout<<genres[i]<<' '<<plays[i]<<' '<<i<<'\n';
        m[genres[i]]+=plays[i];
        n[genres[i]].push_back({plays[i],i});
        genre.insert(genres[i]);
    }
    
    vector<pair<string,int>> temp;
    for(auto t: genre){
        sort(n[t].begin(),n[t].end(),cmp);
        temp.push_back({t,m[t]});
    }
    sort(temp.begin(),temp.end(),upper);
    
    for(auto t: temp){
        //cout<<t.first<<' '<<t.second<<'\n';
        
        if(n[t.first].size() <2){
            for(int i=0;i<n[t.first].size();i++){
            answer.push_back(n[t.first][i].second);
            }
        }
        else{
            for(int i=0;i<2;i++){
            answer.push_back(n[t.first][i].second);
            }

        }
    }
    
    return answer;
}