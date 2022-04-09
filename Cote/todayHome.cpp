#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> answer;

map<char,int> dir;

void getAns(int t,int dis, char a, char b){
    string temp = "Time "+to_string(t)+": Go straight " + to_string(dis*100)+"m and turn";
    if((dir[a]+1)%4 == dir[b]){
        temp+=" right";
    }
    else{
        temp+=" left";
    }
    answer.push_back(temp);
}

vector<string> solution(string path) {

    dir['N'] = 0;
    dir['E'] = 1;
    dir['S'] = 2;
    dir['W'] = 3;

    vector<pair<char,int>> v;

    char c = path[0];
    int cnt = 1;
    for(int i=1;i<path.length();i++){
        if(path[i] == c){
            cnt++;
        }
        else{
            v.push_back({c,cnt});
            cnt=1;
            c = path[i];
        }
    }
    v.push_back({c,cnt});

    int t= 0;
    for(int i=0;i<v.size()-1;i++){

        if(v[i].second <=5){
            getAns(t,v[i].second,v[i].first,v[i+1].first);
            t+=v[i].second;
        }
        else{
            getAns(t+(v[i].second%5),5,v[i].first,v[i+1].first);
            t+=v[i].second;
        }
    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
map<string, int>m;
vector<pair<int, string>> v;
bool check[1002];

map<char,bool> s;

string solution(string call) {
    string answer = "";

    for(int i=0;i<call.length();i++){
        if(call[i]>=65 && call[i]<=90){
            call[i] +=32;
            check[i]=true;
        }
    }

    for(int i=1;i<call.length();i++){
        for(int j=0;j<call.length()-i+1;j++){
            m[call.substr(j,i)]++;
        }
    }

    for(auto t: m){
        v.push_back({t.second,t.first});
    }
    sort(v.begin(),v.end(),greater<>());
    int tempMax=v[0].first;
    for(auto t: v){
        if(t.first==tempMax){
            if(t.second.length()==1){
                s[t.second[0]] = true;
            }
        }
        else break;
    }

    for(int i=0;i<call.length();i++){
        if(s[call[i]]){

        }
        else{
            if(check[i]){
                answer+=call[i]-32;
            }
            else{
                answer+=call[i];
            }
        }

    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<string,string> m;
map<string,string> res;

string solution(string tstring, vector<vector<string>> variables) {
    string answer = "";

    for(int i=0;i<variables.size();i++){
        m[variables[i][0]] = variables[i][1];
    }
    for(auto t: m){
        map<string, bool>check;
        queue<string> q;
        q.push(t.second);
        check[t.first] = true;

        while(!q.empty()){
            string st = q.front();
            q.pop();

            if(st[0]=='{'){
                string temp = st.substr(1,st.size()-2);
                if(check[temp]){
                    res[t.first] = "{"+ temp+"}";
                    break;
                }
                if(m[temp]==""){
                    res[t.first] = st;
                    break;
                }
                q.push(m[temp]);
                check[temp] = true;
            }
            else{
                res[t.first] = st;
                break;
            }
        }
        if(res[t.first]==""){
            res[t.first] = "{" + t.first + "}";
        }
    }



    for(int i=0;i<tstring.length();i++){
        cout<<tstring[i];
        if(tstring[i]=='{'){
            string tem="";
            for(int j=0;j<tstring.length()-i;j++){
                if(tstring[i+j]=='}'){
                    tem = tstring.substr(i+1,j-1);
                    if(res[tem]==""){
                        answer+=tstring.substr(i,j+1);
                        i+=j;
                        break;
                    }
                    else{
                        answer+=res[tem];
                        i +=j;
                        break;
                    }
                }
            }
        }
        else{
            answer+=tstring[i];
        }
    }

    return answer;
}