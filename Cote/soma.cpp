#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N,T;
    cin>>N;

    string temp;
    vector<string> v;
    for(int i=0;i<N;i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    cin>>T;
    while(T--){
        cin>>temp;
        int l = temp.length();
        int res=0;
        for(auto t: v){
            string sub = t.substr(0,l);
            if(sub==temp)res++;
        }
        cout<<res<<'\n';
    }
    
    return 0;
}

#include <iostream>
#include <string>

using namespace std;
int A,B;

char decode(char t){
    int k = t -'a';
    //cout<<k<<' ';
    int res;
    char retu;
    while(1){
        if(((k-B)%A) == 0 ){
            res =k;
            retu = (res-B)/A;
            //cout<<retu<<'\n';
            break;
        }
        k+=26;
        
    }
    return retu + 'a';
}

int main() {
    
    cin>>A>>B;
    string code;
    cin>>code;
    
    string res="";
    for(int i=0;i<code.length();i++){
        res +=decode(code[i]);
    }
    cout<<res;
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int cnt=0;
bool visited[8000][7500];

void go(int level,int index, int total){
    //cout<<level<<' '<<index<<' '<<total<<'\n';
    if(index==3){
        if(total<=2500 && total>=2000){
            cnt++;
        }
        return;
    }

    for(int i=level;i<N;i++){
        if(total>2500 ||visited[i][total+v[i]] ){
            continue;
        }
        else{
            visited[i][total+v[i]] = true;
            go(i+1,index+1,total+v[i]);
        }
    }
}

int main() {
    cin>>N;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        v.push_back(temp);
    }

    go(0,0,0);

    cout<<cnt;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int N;
    cin>>N;
    int resMin = 10001, resMax = -10001;

    vector<int> v;
    v.push_back(a);
    v.push_back(b);

    int x,y,z;
    while(N--){
        cin>>x>>y>>z;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        sort(v.begin(),v.end());

        int low = 0;
        int high = v.size()-1;
        
        int mid1 = (low+high)/3;
        int mid2 = (low+high) -mid1;

        cout<<v[mid1]<<' '<<v[mid2]<<'\n';
    }


    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N,M;
vector<vector<pair<int,int>>>m(100000);
int treasure[100002];
int cost[100002];
int res[100002];

void bfs(){
    queue<pair<int,int>>q;
    q.push({1,0});
    cost[1] = 0;

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int ti = t.first;
        int tcost = t.second;

        if(cost[ti] == -1 || cost[ti] >= tcost){
            cost[ti] = tcost;
        }
        else{
            continue;
        }

        for(auto tt: m[ti]){
            int ni = tt.first;
            int ncost = tt.second;

            q.push({ni,tcost+ ncost});
            cost[ni] = tcost+ ncost;
        }

    }

}

int main() {
    cin>>N>>M;

    int u,v,w;
    for(int i=0;i<N-1;i++){
        cin>>u>>v>>w;
        m[u].push_back({v,w});
    }
    int X,V;
    for(int i=0;i<M;i++){
        cin>>X>>V;
        treasure[X] = V;
    }

    for(int i=1;i<=N;i++){
        cost[i] = -1;
    }

    bfs();

    int aindex=0;
    int answer =-1;
    for(int i=1;i<=N;i++){
        res[i] = treasure[i] - cost[i]*2;
        if(res[i] > answer) {
            answer = res[i];
            aindex = i;
        }
    }

    cout<<aindex<<' '<<answer;
    
    return 0;
}