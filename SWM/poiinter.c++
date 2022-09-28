#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N,M,Q;
    cin>>N>>M>>Q;

    vector<int> v(M+1);

    int temp;
    for(int i=1;i<=M;i++){
        cin>>temp;
        v[i] = temp;
    }

    string s;
    int x,y;
    while(Q--){
        cin>>s;
        if(s=="assign"){
            cin>>x>>y;
            v[x] = v[y];
        }
        else if(s=="swap"){
            cin>>x>>y;
            int t = v[x];
            v[x] = v[y];
            v[y] = t;
        }
        else{
            cin>>x;
            v[x] = 0;
        }
    }
    
    set<int> ss;

    for(auto t: v){
        if(t==0 ) continue;
        ss.insert(t);
    }
    v.clear();

    for(auto tt: ss){
        v.push_back(tt);
    }
    sort(v.begin(),v.end());

    cout<<v.size()<<'\n';
    for(auto t: v){
        cout<<t<<'\n';
    }

    return 0;
}