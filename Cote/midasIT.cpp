#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<long long,long long> m;
vector<int> tempH;

long long minH(int s, int f){
    int res =1000000002;

    for(int i=s;i<=f;i++){
        res = min(res,tempH[i]);
    }

    return res;
}

vector<vector<long long>> solution(vector<int> H) {
    vector<vector<long long>> answer;
    tempH = H;

    for(int i=0;i<H.size();i++){
        for(int j=i;j<H.size();j++){
            int t= minH(i,j);
            m[t]++;
        }
    }

    for(auto t: m){
        answer.push_back({t.first,t.second});
    }

    
    return answer;
}


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int>> comply;
vector<vector<int>> tempL;
int tempN;
int answer = -1;

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

bool unComply(vector<int> f, vector<int>s){
    int fl = f[0];
    int fr = f[2];
    int ft = f[3];
    int fb = f[1];
        
    int sl = s[0];
    int sr = s[2];
    int st = s[3];
    int sb = s[1];

    if(fl > sr || fr < sl || ft < sb || fb > st){
        return true;
    }
    else{
        return false;
    }
}

bool available(vector<vector<int>> l){
    for(int i=0;i<tempN-1;i++){
        for(int j=i+1;j<tempN;j++){
            if(unComply(l[i],l[j])){
                continue;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

void go(int cnt,int index, vector<vector<int>> l){
    if(cnt>20) return;

    if(index >= comply.size()-1){
        if(available(l)){
            if(answer == -1 || answer > cnt)answer = cnt;
        }
    }
    

    auto change = comply[index];
    vector<int> f = l[change.first];
    vector<int> s = l[change.second];
    int fl = f[0];
    int fr = f[2];
    int ft = f[3];
    int fb = f[1];
        
    int sl = s[0];
    int sr = s[2];
    int st = s[3];
    int sb = s[1];

    for(int k=0;k<4;k++){
        int con =1;

        while(1){
            if(cnt + con >20) break;
            int ni = di[k]*con;
            int nj = dj[k]*con;
            vector<int>newf;
            int fnl = fl + nj;
            int fnr = fr + nj;
            int fnt = ft + ni;
            int fnb = fb + ni;
            newf.push_back(fnl);
            newf.push_back(fnb);
            newf.push_back(fnr);
            newf.push_back(fnt);
            l[change.first] = newf;

            if(unComply(l[change.first], l[change.second])){
                go(cnt+con,index+1,l);
            }
            con++;
        }
    }
    l[change.first] = f;
    for(int k=0;k<4;k++){
        int con =1;

        while(1){
            if(cnt + con >20) break;
            int ni = di[k]*con;
            int nj = dj[k]*con;
            vector<int>news;
            int snl = sl + nj;
            int snr = sr + nj;
            int snt = st + ni;
            int snb = sb + ni;
            news.push_back(snl);
            news.push_back(snb);
            news.push_back(snr);
            news.push_back(snt);
            l[change.second] = news;

            if(unComply(l[change.first], l[change.second])){
                go(cnt+con,index+1,l);
            }
            con++;
        }
    }
}


int solution(int N, vector<vector<int>> L) {

    for(int i=0;i<N;i++){
        vector<int> newT;
        auto t = L[i];
        int tl = min(t[0],t[2]);
        int tr = max(t[0],t[2]);
        int tt = max(t[1],t[3]);
        int tb = min(t[1],t[3]);
        newT.push_back(tl);
        newT.push_back(tb);
        newT.push_back(tr);
        newT.push_back(tt);
        L[i] = newT;
    }

    tempL = L;
    tempN = N;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(unComply(L[i],L[j])){
                continue;
            }
            else{
                comply.push_back({i,j});
            }
        }
    }

    go(0,0,L);

    return answer;
}